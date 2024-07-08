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
