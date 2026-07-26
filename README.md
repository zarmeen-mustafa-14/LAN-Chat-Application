<div align="center">

<img src="https://readme-typing-svg.demolab.com?font=JetBrains+Mono&weight=600&size=30&duration=3500&pause=1200&color=2F81F7&center=true&vCenter=true&width=900&lines=C%2B%2B+LAN+Multi-Client+Chat+Application;Modern+C%2B%2B20+%7C+WinSock2+%7C+TCP%2FIP;Client-Server+Architecture;Thread-per-Client+Concurrency;Object-Oriented+Design+%7C+RAII" />

<br>

<p>
<img src="https://img.shields.io/badge/C++-20-00599C?style=for-the-badge&logo=cplusplus&logoColor=white"/>
<img src="https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white"/>
<img src="https://img.shields.io/badge/Networking-WinSock2-success?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Protocol-TCP/IP-blue?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Architecture-Client--Server-orange?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Concurrency-Thread--per--Client-purple?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Status-In%20Development-brightgreen?style=for-the-badge"/>
</p>

<img src="https://github-readme-tech-stack.vercel.app/api/cards?title=Tech+Stack&align=center&titleAlign=center&fontSize=20&lineCount=2&theme=github_dark&line1=cplusplus,C%2B%2B20,00599C;cmake,CMake,064F8C;windows,WinSock2,0078D6;&line2=git,Git,F05032;github,GitHub,181717;visualstudio,Visual+Studio,5C2D91;" />

---

### 💬 Professional LAN Multi-Client Chat Application built with Modern C++20, WinSock2 & TCP/IP.

*A modular, scalable and object-oriented client-server application featuring structured messaging, thread-per-client concurrency, RAII, and clean software architecture.*

</div>

---

# 🚀 Live Project Overview

```text
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🟢 Server Status            Ready

🟢 Architecture             Client-Server

🟢 Networking               WinSock2

🟢 Protocol                 TCP/IP

🟢 Language                 Modern C++20

🟢 Concurrency              Thread-per-Client

🟢 Design                   Object-Oriented

🟢 Resource Management      RAII

🟢 Build System             CMake

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

---

# ✨ Features

| | |
|:--|:--|
| 💬 | Multi-client LAN communication |
| 🌐 | TCP/IP networking |
| 🔄 | Thread-per-client concurrency |
| 📦 | Structured messaging |
| ⚡ | Serialization & Parsing |
| ✅ | Message validation |
| 📡 | Broadcast messaging |
| 🔒 | Safe resource management (RAII) |
| 🧠 | Modern C++20 |
| 📝 | Logging system |
| ⚙️ | Configuration loader |
| 🧩 | Modular architecture |
| 🎯 | SOLID principles |
| 🚀 | Extensible architecture |

---

# 🏗 System Architecture

```text
                     +--------------------+
                     |       SERVER       |
                     +---------+----------+
                               │
               ┌───────────────┼───────────────┐
               │               │               │
        +------+-----+   +------+-----+   +------+-----+
        |   Client 1 |   |   Client 2 |   |   Client N |
        +------------+   +------------+   +------------+

               TCP/IP Communication over LAN
```

---

# 📂 Project Structure

```text
📦 project
│
├── 📁 common
│   ├── Message
│   ├── Protocol
│   ├── Serializer
│   ├── Parser
│   └── MessageValidator
│
├── 📁 server
│   ├── core
│   ├── network
│   └── services
│
├── 📁 client
│   ├── core
│   ├── network
│   ├── services
│   └── ui
│
├── 📁 infrastructure
│   ├── logging
│   └── config
│
├── 📁 tests
│
└── 📄 CMakeLists.txt
```

---

# 📡 Communication Pipeline

```text
ConsoleUI
      │
      ▼
NetworkClient
      │
      ▼
Sender
      │
      ▼
═══════════════════════════════════════
        TCP/IP via WinSock2
═══════════════════════════════════════
      ▲
      │
Receiver
      │
      ▼
Parser
      │
      ▼
MessageDispatcher
      │
      ▼
Broadcaster
      │
      ▼
Connected Clients
```

---

# 🧵 Thread Model

```text
Server
   │
   ▼
Listener
   │
   ▼
ConnectionAcceptor
   │
   ▼
ClientManager
   │
   ▼
ClientSession
   │
   ├──────────────► std::thread
   │
   └──────────────► Handles one client
```

Every connected client owns its own communication thread.

---

# 🛠 Technology Stack

| Category | Technology |
|----------|------------|
| 💻 Language | Modern C++20 |
| 🌐 Networking | WinSock2 |
| 📡 Protocol | TCP/IP |
| 🧵 Concurrency | std::thread |
| 🔐 Synchronization | std::mutex |
| 📦 Build | CMake |
| 🖥 IDE | Visual Studio |
| 🪟 Platform | Windows |

---

# 📊 Project Statistics

| Metric | Value |
|:-------|------:|
| Modules | 4 |
| Classes | 24 |
| Executables | 2 |
| Communication | TCP/IP |
| Networking API | WinSock2 |
| Concurrency Model | Thread-per-Client |
| Design Pattern | Composition |
| Memory Management | RAII |
| Ownership | std::unique_ptr |

---

# 🎯 Core Components

| Module | Responsibility |
|---------|---------------|
| 📦 Common | Shared communication protocol |
| 🖥 Server | Connection management & broadcasting |
| 💬 Client | User interaction & networking |
| ⚙ Infrastructure | Logging & configuration |

---

# 🔮 Roadmap

- ✅ TCP/IP Communication
- ✅ Modular Architecture
- ✅ Thread-per-Client
- ✅ Logging System
- ✅ Configuration Support
- ⏳ Private Messaging
- ⏳ Authentication
- ⏳ Chat Rooms
- ⏳ File Transfer
- ⏳ Encryption
- ⏳ GUI Client
- ⏳ Persistent Chat History

---

# 📄 License

This project is licensed under the **MIT License**.

---

<div align="center">

**Built with Modern C++20 • WinSock2 • TCP/IP • Object-Oriented Design**

</div>
