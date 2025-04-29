#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <algorithm>
#include <limits>

using namespace std;

// Constants
const int SHOP_PRICE = 20;
const int MAX_PENALTIES = 5;
const int MIN_STAT = 0;
const int MAX_STAT = 100;
const int STAT_BOOST = 20;
const int INITIAL_BUDGET = 100;
const int INITIAL_STAT = 10;

class SoccerPlayer {
private:
    string name;
    string gender;
    string strongFoot;
    int shotPower;
    int accuracy;
    int diving;
    int budget;

    void clampStats() {
        shotPower = max(MIN_STAT, min(shotPower, MAX_STAT));
        accuracy = max(MIN_STAT, min(accuracy, MAX_STAT));
        diving = max(MIN_STAT, min(diving, MAX_STAT));
    }

public:
    SoccerPlayer(string name, string gender, string strongFoot) {
        this->name = name;
        this->gender = gender;
        this->strongFoot = strongFoot;
        this->shotPower = INITIAL_STAT;
        this->accuracy = INITIAL_STAT;
        this->diving = INITIAL_STAT;
        this->budget = INITIAL_BUDGET;
    }

    void enterToContinue() {
        cout << "\nPress Enter to continue.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    void handleRandomEvent(int randomNumber) {
        if (randomNumber == 0) {
            cout << "\n⚠️ Training Mishap! You tripped during drills.\n";
            cout << "➖ -5 Accuracy\n";
            accuracy -= 5;
        }
        else if (randomNumber == 1) {
            cout << "\n🥤 Smooth Boost! The team nutritionist handed you a smoothie.\n";
            cout << "➕ +5 Shot Power\n";
            shotPower += 5;
        }
        else if (randomNumber == 2) {
            cout << "\n😵 Oops! You skipped breakfast by accident.\n";
            cout << "➖ -5 Shot Power\n";
            shotPower -= 5;
        }
        else if (randomNumber == 4) {
            cout << "\n🎯 Bullseye! You hit every target in training.\n";
            cout << "➕ +10 Accuracy\n";
            accuracy += 10;
        }
        else if (randomNumber == 5) {
            cout << "\n🧦 Bad Luck! You lost your favorite socks before the game.\n";
            cout << "➖ -5 Diving\n";
            diving -= 5;
        }
        else if (randomNumber == 6) {
            cout << "\n🎁 Fan Favor! Someone gave you a lucky wristband.\n";
            cout << "➕ +5 Diving\n";
            diving += 5;
        }
        else if (randomNumber == 7) {
            cout << "\n📵 Sleep Deprived! Stayed up too late scrolling on your phone.\n";
            cout << "➖ -5 to ALL STATS (Shot Power, Accuracy, Diving)\n";
            shotPower -= 5;
            accuracy -= 5;
            diving -= 5;
        }
        else if (randomNumber == 8) {
            cout << "\n⚡ Power Surge! That energy drink kicked in right on time.\n";
            cout << "➕ +5 to ALL STATS (Shot Power, Accuracy, Diving)\n";
            shotPower += 5;
            accuracy += 5;
            diving += 5;
        }

        clampStats();
        enterToContinue();
    }

    void playerInfo() {
        cout << "\n================= PLAYER INFO =================\n"
             << "| Name       : " << name << "\n"
             << "| Gender     : " << gender << "\n"
             << "| Strong Foot: " << strongFoot << "\n"
             << "| Shoot Power: " << shotPower << "\n"
             << "| Accuracy   : " << accuracy << "\n"
             << "| Diving     : " << diving << "\n"
             << "| Budget     : " << budget << "\n"
             << "==============================================\n\n";

        enterToContinue();
    }

    void statsDisplay() {
        cout << "\n=========== 📊 PLAYER STATS 📊 ===========\n"
             << "🧬 Shoot Power: " << shotPower << "\n"
             << "Accuracy: " << accuracy << '\n'
             << "Diving: " << diving << '\n'
             << "💰 Budget : $" << budget << "\n"
             << "==========================================\n";
    }

    void boostShop() {
        char option;
        cout << "\n=========== ⚡ BOOST SHOP ⚡ ===========\n"
             << "Budget: $" << budget << "\n"
             << "----------------------------------------\n"
             << "Current Shoot Power: " << shotPower << "\n"
             << "Current Accuracy: " << accuracy << "\n"
             << "Current Diving: " << diving << "\n"
             << "----------------------------------------\n"
             << "[B] Banana 🍌        | +" << STAT_BOOST << " Shot Power | -$" << SHOP_PRICE << "\n"
             << "[A] Apple 🍎         | +" << STAT_BOOST << " Accuracy   | -$" << SHOP_PRICE << "\n"
             << "[P] Protein Bar 💪   | +" << STAT_BOOST << " Diving     | -$" << SHOP_PRICE << "\n"
             << "----------------------------------------\n"
             << "Choose your snack (B/A/P): ";
        
        cin >> option;
        option = toupper(option);

        while(option != 'B' && option != 'A' && option != 'P') {
            cout << "Invalid input. Enter B, A, or P: ";
            cin >> option;
            option = toupper(option);
        }

        if (budget < SHOP_PRICE) {
            cout << "❌ Not enough budget! You need $" << SHOP_PRICE << "\n";
            return;
        }

        budget -= SHOP_PRICE;

        switch(option) {
            case 'B':
                shotPower += STAT_BOOST;
                cout << "🍌 Banana Boost! +" << STAT_BOOST << " Shot Power 💥\n";
                break;
            case 'A':
                accuracy += STAT_BOOST;
                cout << "🍎 Apple Power! +" << STAT_BOOST << " Accuracy 🎯\n";
                break;
            case 'P':
                diving += STAT_BOOST;
                cout << "💪 Protein Bar! +" << STAT_BOOST << " Diving Reflexes 🧤\n";
                break;
        }

        clampStats();
        enterToContinue();
        statsDisplay();
    }
};







   // Function to return the introduction and rules as a string
   string introduction(string name) {
    string intro = "Welcome to the Soccer Tournament Showdown, " + name + "!\n";
    intro += "In this penalty shootout game, players and the computer take turns attempting to score penalties.\n";
    intro += "The game follows these rules:\n\n";

    intro += "- 5 penalty shots for each team.\n";
    intro += "  Both you and the computer will get 5 shots each, alternating between shooter and goalkeeper.\n";
    intro += "  After 5 rounds, the team with the most goals wins the match.\n\n";

    intro += "- Boost Shop Between Games.\n";
    intro += "  You will have access to a boost shop after each game to purchase items like bananas or chocolates.\n";
    intro += "  These items provide advantages such as helping with penalty shot success or giving minor boosts to the next game.\n\n";

    intro += "- Random Event Between Games.\n";
    intro += "  A random event can take place between games. It could be something like:\n";
    intro += "    - Weather changes: rain or wind that affects accuracy.\n";
    intro += "    - Lucky break: a random boost to either your penalty shots or the opponent's.\n";
    intro += "    - Player injury: a temporary setback that reduces your stats for the next round.\n";
    intro += "    - Free Item: Get an extra item for your boost shop.\n";
    intro += "  These events add an element of unpredictability to the game, keeping things exciting!\n\n";

    intro += "- Lose and You're Out.\n";
    intro += "  If you lose a match, you're out of the tournament. There are no second chances in this knockout-style competition.\n";
    intro += "  Win each game to advance to the next round until the final showdown!\n\n";

    intro += "These are the fundamental rules for the game. Now let's get into the exciting part: the gameplay!\n\n";

    return intro;
}

void displayGoal(int &round) {
    cout << "Round: " << round << '\n';
    round++;

    string goalFrame[7] = {
        " _____________",
        "|      O      |",
        "|    /|||\\    |",
        "|   # ||| #   |",
        "|    /   \\    |",
        "|   /     \\   |",
        "|  #       #  |"
    };
    
    for(int i = 0; i < 7; i++) {
        cout << goalFrame[i] << '\n';
    }
}

bool userPenalty() {
    string options = "LRM";
    char computerChoice = options[rand() % options.length()];
    char yourChoice;
    
    cout << "Pick where to shoot: (L, R, M): \n";
    cin >> yourChoice;
    yourChoice = toupper(yourChoice);

    while (yourChoice != 'L' && yourChoice != 'M' && yourChoice != 'R') {
        cout << "Invalid input. Enter L, M, or R: ";
        cin >> yourChoice;
        yourChoice = toupper(yourChoice);
    }

    return (yourChoice != computerChoice);
}

bool userGoalkeeper() {
    string options = "LRM";
    char computerChoice = options[rand() % options.length()];
    char yourChoice;

    cout << "Pick where to dive: (L, R, M): \n";
    cin >> yourChoice;
    yourChoice = toupper(yourChoice);
    
    while (yourChoice != 'L' && yourChoice != 'M' && yourChoice != 'R') {
        cout << "Invalid input. Enter L, M, or R: ";
        cin >> yourChoice;
        yourChoice = toupper(yourChoice);
    }

    return (yourChoice == computerChoice);
}

void scoreBoard(int &playerScore, int &compScore, bool &userTurn, int &playerAttempt, int &compAttempt) {
    cout << "\n\n";
    cout << "===========================\n";

    if (userTurn) {
        cout << "🎯 PLAYER'S TURN TO SHOOT\n";
        cout << "===========================\n\n";

        playerAttempt++;
        if (userPenalty()) {
            cout << "\n⚽ Penalty Scored!\n";
            playerScore++;
        } else {
            cout << "\n🧤 Saved by the keeper!\n";
        }

        cout << "\n➡️  Player Attempt: " << playerAttempt << "\n";
        userTurn = false;

        cout << "\n\n🔄 Switching to Computer...\n";
        cout << "Press Enter to continue.\n";
        cin.ignore();
        cin.get();
    }
    else {
        cout << "🤖 COMPUTER'S TURN TO SHOOT\n";
        cout << "===========================\n\n";

        compAttempt++;
        if (userGoalkeeper()) {
            cout << "\n🧤 You Saved It!\n";
        } else {
            cout << "\n⚽ Goal by the Computer!\n";
            compScore++;
        }

        cout << "\n➡️  Computer Attempt: " << compAttempt << "\n";
        userTurn = true;

        cout << "\n\n🔄 Switching to Player...\n";
        cout << "Press Enter to continue.\n";
        cin.ignore();
        cin.get();
    }

    cout << "\n\n";
    cout << "┌────────────────────────┐\n";
    cout << "│     🏆  SCOREBOARD     │\n";
    cout << "├────────────────────────┤\n";
    cout << "│ 👤 Player     : " << playerScore << "      │\n";
    cout << "│ 🤖 Computer   : " << compScore << "      │\n";
    cout << "└────────────────────────┘\n";
    cout << "\n\n";
}

void displayBracket(int level) {
    cout << "\n\n======= TOURNAMENT BRACKET =======\n\n";

    string rounds[6] = {
        "Round of 32",
        "Round of 16",
        "Quarterfinal",
        "Semifinal",
        "Final",
        "🏆 CHAMPIONS 🏆"
    };

    for (int i = 0; i < 6; i++) {
        if (i < level - 1) {
            cout << "[✓] " << rounds[i] << "\n";
        } else if (i == level - 1) {
            cout << "[🔴] " << rounds[i] << " <-- You are here\n";
        } else {
            cout << "[ ] " << rounds[i] << "\n";
        }
    }

    cout << "\n==================================\n";
}

void nextLevel(int &level) {
    level++;
    cout << "\n\n🎉🎉🎉 YOU ADVANCE TO THE NEXT ROUND! 🎉🎉🎉\n\n";
    displayBracket(level);
    
    cout << "\nPress Enter to continue.\n";
    cin.ignore();
    cin.get();
}

string gameOverMessage() {
    return "\n\n=======================================\n"
           "              GAME OVER\n"
           "=======================================\n\n"
           "The crowd falls silent. The final whistle blows.\n"
           "You've given it your all, but the journey ends here.\n"
           "Sometimes, even the best fall short — that's the beauty of the game.\n\n"
           "Hold your head high. There's always a next time.\n"
           "Thanks for playing!\n"
           "\nPress Enter to exit.\n";
}

void winningChampionMessage() {
    cout << "\n\n🏆🏆🏆=============================================🏆🏆🏆\n";
    cout << "              YOU ARE THE WORLD CHAMPION!\n";
    cout << "🏆🏆🏆=============================================🏆🏆🏆\n\n";
    
    cout << "The final whistle blows... THE CROWD ERUPTS!\n";
    cout << "Confetti rains from the sky. Your teammates swarm you in celebration.\n";
    cout << "After a grueling tournament, YOU stand alone at the top!\n\n";
    
    cout << "🥇 Your name is written in the history books.\n";
    cout << "🥅 Every goal, every save — it all led to THIS moment.\n";
    cout << "🎉 You didn't just play the game… you OWNED it.\n\n";
    
    cout << "This isn't just a win. This is LEGENDARY.\n";
    cout << "🏆 The trophy is yours. You are the champion of the world. 🏆\n";

    cout << "\nPress Enter to lift the trophy...\n";
    cin.ignore();
    cin.get();
}

void draw(int &playerScore, int &compScore, bool &userTurn, int &playerAttempt, int &compAttempt, int &round) {
    cout << "\n================ ⚠️ SUDDEN DEATH ⚠️ ================\n"
         << "🤯 It's all tied after 5 penalties each!\n"
         << "💥 Next goal could win it. Next miss could end it.\n"
         << "🧠 Stay sharp. 💪 Stay strong. 🎯 It's sudden death time!\n"
         << "=====================================================\n\n";

    displayGoal(round);
    scoreBoard(playerScore, compScore, userTurn, playerAttempt, compAttempt);
}



    
    
    
    
     



  
    












int main() {
    srand(time(0));

    int playerScore = 0;
    int compScore = 0;
    bool userTurn = true;  // Initialize turn
    bool gameOn = true;
    string name, gender, strongFoot;
    int round = 1;
    int playerAttempt = 0;
    int compAttempt = 0;
    int level = 1;

    cout << "Name: \n";
    getline(cin, name);
    cout << "Gender: \n";
    getline(cin, gender);
    cout << "Strong foot: \n";
    getline(cin, strongFoot);

    SoccerPlayer player(name, gender, strongFoot);
    player.playerInfo();

    // Display introduction text character by character
    for(char ch : introduction(name)) {
        cout << ch << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    
    displayBracket(level);

    while(gameOn) {
        playerAttempt = 0;
        compAttempt = 0;
        round = 0;
        playerScore = 0;
        compScore = 0;

        while(playerAttempt < 6 && compAttempt < 6) {
            if(playerAttempt == 5 && compAttempt == 5) {
                break;
            }
            
            displayGoal(round);
            scoreBoard(playerScore, compScore, userTurn, playerAttempt, compAttempt);
            player.statsDisplay();
        }

        if(level == 5 && playerScore > compScore) {
            displayBracket(level);
            winningChampionMessage();
            break;
        }

        if(playerScore == compScore) {
            bool noWinner = true;

            while(noWinner) {
                draw(playerScore, compScore, userTurn, playerAttempt, compAttempt, round);

                if(playerAttempt == compAttempt && playerScore != compScore)
                    break;
            }
        }

        if(playerScore > compScore) {
            int randomNumber = rand() % 9;
            nextLevel(level);
            player.handleRandomEvent(randomNumber);
            player.boostShop();
        }
        else {
            gameOn = false;
            break;
        }
    }

    for(char a : gameOverMessage()) {
        cout << a << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    
    cin.ignore();
    cin.get();

    return 0;
}




