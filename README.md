# Unreal Multiplayer Test
Multiplayer Test in Unreal Engine 5

This course is to learn some multiplayer stuff and things to create a videogames in unreal engine: latency, conection,... First of all, using a VPN and later with a pretty UMG menu, with C++, using all the network. And finish with Steam services to make easy conections

Conecting two intances in the same machine or in a local network using [Hamachi](https://www.vpn.net/).

**Note:** Original Course uses Unreal Engine 4. I use Unreal 5.2 in this repository.

### Differences UE5 vs U4
- Differences in Interface in Unreal Editor.

## Connecting Two Players
- Use a Third Person Template. No Started content and C++ template.
- In play submenu, select number of players to 2. and Net Mode as _Play As Listen Server_. The editor will act as both a Server and a Client. And any Instances as Players.

### Under the Hood
- Unreal Loads a **Map**
- The **maps** specifies a **GameMode**
- The **PlayerController** joins the **Map**
- It ask the **GameMode** to Spawn a **Pawn**
- The **Pawn** is linked to the **PlayerController**.

## Multiplayer Games : Types
- Turn based : Chess
	- Must be Synchronous? NO
	- Session Length: Variable
	- As a indie developer, suitability? No problem
	- Unreal Support: Minimalz
- Real-time session-bassed : First Person Shooter
	- Must be Synchronous? YES
	- Session Length: Less than 1 hour
	- As a indie developer, suitability? Good
	- Unreal Support: Perfect, of course. Unreal born as a FPS engine.
- MMO and Persistent World :
	- Must be Synchronous? YES
	- Session Length: Potentially infinite
	- As a indie developer, suitability? Technical aspect to cover, difficult
	- Unreal Support: Minimal

### Session-Based Stages (3)
 1. Discovery. Find a session to Join
 2. Connection. Hooking up to client.
 3. Synchronisation. Players see the same.

First of all, Connecction is the first thing to learn. Using Unreal stuff that done it for us.

## Meet the Client-Server Model
Peer-to-Peer Architecture
- All players update state with inputs from everybody
- Must wait for the slower player. Very slow game
- Security problem: Cheating and sending inputs for win.

Client-Server Architecture
- Server based game
- Unreal uses this model

Let's try in Unreal
- Open a command propmt
- Run your project using Unreal Editor in CMD. with -game parameter. (Alt+Enter)
- Use -log to wathch loading and log during the game is running
- To load some map use /Game/name pad full/filemapname before -game
- You can put a IP address instead a map file.
	- Use -server instead -game to launch a server first and some clients using you IP address.
		- Use /Game/name apd full/filemapname?listen if you have black screen problems
		- Other problem is the port to listen. Search in log "listening" add remember port number. Add that port server number to IP address with :
		- Use 127.0.0.1 instead if you still have problems 
		
## Detecting Where Code is Running
Behviours in Server and in Client.

Creating a moving platform.

**MovingPlatform.h**
```cpp
#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER3RDPERSON_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	double Speed = 20.0;

};
```
**MovingPlatform.cpp**
```cpp
#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		Location += FVector(0.0, Speed * DeltaTime, 0.0);
		SetActorLocation(Location);
	}
}
```
The Code run on both, the server and the client.
There are some metho calls that allow us to detect whether we are the client or whether we are the server, namely that method call it **HasAuthority()** that returns a boolean true if you are **Server** running and false is you are a client.

*Note: Remember to run Unreal Editor with Net Mode -> Play as Listen Server. To create a client and a server*





