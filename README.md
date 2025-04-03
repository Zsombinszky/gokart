# 🏎️ Go-Kart Racing Simulation System

## 🌟 Overview

A complete object-oriented simulation system for managing go-kart races, featuring:

- **Guest management** (Adults & Children)
- **Gokart fleet** with different vehicle types
- **Custom race tracks** with varying difficulty
- **Race organization** with safety validation

## 🧩 Key Components

### 🧑‍🤝‍🧑 Guest System

| Class        | Description             | Special Features                 |
|--------------|-------------------------|----------------------------------|
| `Guest`      | Abstract base class     | Skill levels, safety equipment   |
| `ChildGuest` | For young racers (5-12) | Color preferences, height limits |
| `AdultGuest` | For older racers (18+)  | Advanced kart permissions        |

### 🚗 Gokart Types

| Type          | Max Speed | Features                      |
|---------------|-----------|-------------------------------|
| `SmallGokart` | 30 km/h   | Foam protection, funny honk   |
| `BigGokart`   | 80 km/h   | Sport mode, roll cage         |
| `RaceGokart`  | 100 km/h  | Turbo boost, overtake signals |

## 🛠️ Installation

```bash
# Clone repository
git clone https://github.com/Zsombinszky/gokart.git

# Build with CMake
mkdir build && cd build
cmake ..
make
```

## 🎮 Usage Example

```cpp
// Create a beginner race
auto map = std::make_shared<BeginnerMap>("Rainbow Road");
TrackLead lead("Mario");
Race race(map, lead);

// Add participants
auto child = std::make_shared<ChildGuest>("Luigi", "Green", 10, 140, SkillLevel::Beginner);
race.addRacer(child);

// Start the race!
race.startRace();
```

## 📊 Class Relationships

- **Check out the gokart.puml file**

## 🏆 Features

- ✅ Realistic race simulation
- ✅ Safety validation system
- ✅ Customizable kart fleets
- ✅ Multiple track difficulties
- ✅ Comprehensive class hierarchy

---

<div align="center">
  <h3>🚀 Start your engines! 🚀</h3>
  <img src="https://media.giphy.com/media/3o7TKSjRrfIPjeiVyM/giphy.gif" width="200">
</div>



