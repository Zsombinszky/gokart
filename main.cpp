#include <iostream>
#include <memory>
#include "src/model/guest/AdultGuest.h"
#include "src/model/guest/ChildGuest.h"
#include "src/model/kart/BigGokart.h"
#include "src/model/kart/SmallGokart.h"
#include "src/model/map/BeginnerMap.h"
#include "src/model/race/Race.h"
#include "src/model/staff/TrackLead.h"
#include "src/model/kart/RaceGokart.h"

std::vector<std::shared_ptr<Guest>> createGuests() {
    std::vector<std::shared_ptr<Guest>> guests;

    // Create child guests (using make_shared)
    auto child1 = std::make_shared<ChildGuest>("Benjamin Carter", "Benji", 11, 135, SkillLevel::Intermediate,
                                               Color::Black);
    auto child2 = std::make_shared<ChildGuest>("Alexander Johnson", "Alex", 10, 140, SkillLevel::Beginner,
                                               Color::Silver);
    auto child3 = std::make_shared<ChildGuest>("Olivia Thompson", "Livvy", 9, 125, SkillLevel::Beginner, Color::Pink);
    auto child4 = std::make_shared<ChildGuest>("Theodor Miller", "Teddy", 12, 150, SkillLevel::Advanced, Color::Yellow);
    auto child5 = std::make_shared<ChildGuest>("Charlotte Davis", "Lottie", 7, 110, SkillLevel::Beginner, Color::Green);
    auto child6 = std::make_shared<ChildGuest>("Nathaniel Wilson", "Nate", 8, 115, SkillLevel::Intermediate,
                                               Color::Orange);
    auto child7 = std::make_shared<ChildGuest>("Emily Robinson", "Emmy", 9, 130, SkillLevel::Beginner, Color::Purple);
    auto child8 = std::make_shared<ChildGuest>("Zachary Hall", "Zacky", 12, 140, SkillLevel::Advanced, Color::Red);
    auto child9 = std::make_shared<ChildGuest>("Madeline Clark", "Maddie", 10, 135, SkillLevel::Intermediate,
                                               Color::Blue);
    auto child10 = std::make_shared<ChildGuest>("Samuel Lewis", "Sammy", 11, 155, SkillLevel::Pro, Color::Gold);
    auto child11 = std::make_shared<ChildGuest>("Sophia Martinez", "Sophie", 6, 105, SkillLevel::Beginner,
                                                Color::Black);
    auto child12 = std::make_shared<ChildGuest>("Daniel Anderson", "Danny", 8, 120, SkillLevel::Intermediate,
                                                Color::Green);

    // Create adult guests
    auto adult1 = std::make_shared<AdultGuest>("Alice Johnson", "AJ", 28, 170, SkillLevel::Intermediate);
    auto adult2 = std::make_shared<AdultGuest>("Bob Smith", "BigBob", 35, 185, SkillLevel::Advanced);

    // Add all guests to vector
    guests.push_back(child1);
    guests.push_back(child2);
    guests.push_back(child3);
    guests.push_back(child4);
    guests.push_back(child5);
    guests.push_back(child6);
    guests.push_back(child7);
    guests.push_back(child8);
    guests.push_back(child9);
    guests.push_back(child10);
    guests.push_back(child11);
    guests.push_back(child12);
    guests.push_back(adult1);
    guests.push_back(adult2);

    return guests;
}

std::vector<std::shared_ptr<Gokart>> createGokartFleet(int smallCount, int bigCount, int raceCount) {
    std::vector<std::shared_ptr<Gokart>> fleet;

    for (int i = 1; i <= smallCount; ++i) {
        std::string serial = "SM" + std::to_string(i);
        fleet.push_back(std::make_shared<SmallGokart>(serial));
    }

    for (int i = 1; i <= bigCount; ++i) {
        std::string serial = "BG" + std::to_string(i);
        fleet.push_back(std::make_shared<BigGokart>(serial));
    }

    for (int i = 1; i <= raceCount; ++i) {
        std::string serial = "RG" + std::to_string(i);
        fleet.push_back(std::make_shared<RaceGokart>(serial));
    }

    return fleet;
}

void printRaceHeader(Race &race) {
    std::cout << "=== Race Setup ===" << std::endl;
    std::cout << "Track: " << race.getMap()->getName() << std::endl;
    std::cout << "Track Lead: " << race.getTrackLead().getName() << std::endl;
    std::cout << "Total Racers: " << race.getRacers().size() << std::endl;
    std::cout << "Available Karts: " << race.getAvailableGokarts().size() << std::endl;
}

void printGroupDetails(std::vector<std::shared_ptr<Guest>> &group) {
    std::cout << "\n Group Members:" << std::endl;
    for (const auto &guest: group) {
        std::cout << "- " << guest->getNickName()
                  << " (Age: " << guest->getAge()
                  << ", Skill: " << toString(guest->getSkillLevel()) << ")" << std::endl;
    }
    std::cout << "\n=== Group Created ===" << std::endl;
    std::cout << "Group Size: " << group.size() << std::endl;
}

void equipSafetyGear(std::vector<std::shared_ptr<Guest>> &group) {
    for (const auto &guest: group) {
        guest->setHasMaskOn(true);
        guest->setHasHelmetOn(true);
    }
}

void assignKartsToGroup(std::vector<std::shared_ptr<Guest>> &group, Race &race) {
    std::cout << "\n=== Kart Assignments ===" << std::endl;
    for (const auto &guest: group) {
        bool assigned = race.assignGokart(guest, GokartType::Small);
        std::cout << guest->getNickName()
                  << (assigned ? " got a kart" : " no kart available") << "\n";
    }
}

void printKartFeatures(const std::map<std::shared_ptr<Guest>, std::shared_ptr<Gokart>> &assignments) {
    std::cout << "\n=== Kart Features ===" << std::endl;
    for (const auto &[guest, gokart]: assignments) {
        std::cout << guest->getNickName() << toString(gokart->getType()) << " gokart: "
                  << gokart->getSpecialFeatures() << std::endl;
    }
}

bool validateGroup(const TrackLead &lead, const std::vector<std::shared_ptr<Guest>> &group) {
    std::cout << "\n=== Safety Validation ===" << std::endl;
    bool allValid = true;
    for (const auto &guest: group) {
        if (!lead.validateGuest(guest)) {
            std::cout << guest->getNickName()
                      << " missing safety gear\n";
            allValid = false;
        }
    }
    std::cout << "Every guest of the group successfully validated!" << std::endl;
    return allValid;
}

void runSimulationForChildGuestsAndBeginnerMap() {
    try {
        auto generatedGuests = createGuests();
        TrackLead lead("Mr Anderson");

        auto beginnerMap = std::make_shared<BeginnerMap>("Rainbow Raceway");
        Race race(beginnerMap, lead);

        auto karts = createGokartFleet(beginnerMap->getMaxRacers(), 0, 0);
        race.addGokarts(karts);

        for (const auto &guest: generatedGuests) {
            race.addRacer(guest);
        }

        printRaceHeader(race);

        int maxRacers = race.getMap()->getMaxRacers();
        auto beginnerGroup = lead.createGroupBySkill(race.getRacers(), SkillLevel::Beginner, maxRacers);

        printGroupDetails(beginnerGroup);

        equipSafetyGear(beginnerGroup);

        race.performMaintenanceOnAssignedGokarts();

        assignKartsToGroup(beginnerGroup, race);

        printKartFeatures(race.getAssignments());

        if (validateGroup(lead, beginnerGroup)) {
            race.setValidatedGroup(beginnerGroup);
            race.startRace();
            std::cout << "\nRace started successfully!\n";
        } else {
            std::cout << "\nCannot start race - safety violations!\n";
        }
    } catch (const std::exception &e) {
        std::cerr << "Simulation error: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "=== Gokart Racing Simulation ===" << std::endl;
    runSimulationForChildGuestsAndBeginnerMap();
    return 0;
}