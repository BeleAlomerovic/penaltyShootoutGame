#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

class soccerPlayer{
    public:
    string name;
    string gender;
    string strongFoot; 
    int shotPower;
    int accuracy;
    int diving;
    int budget;



    soccerPlayer(string name, string gender, string strongFoot){
        this-> name = name;
        this-> gender = gender;
        this-> strongFoot = strongFoot;
        this-> shotPower = 10;
        this-> accuracy = 10;
        this-> diving = 10;
        this-> budget = 100;
    }

    
    void rand(int &randomNumber){
        
        
        
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
        

        if(shotPower < 0){
            shotPower = 0;
         }
 
         else if(accuracy < 0){
             accuracy = 0;
         }
 
         else if(diving < 0){
             diving = 0;
         }
 
         else if(shotPower > 100){
             shotPower = 100;
         }
         else if(accuracy > 100){
             accuracy = 100;
         }
 
         else if(diving > 100){
             diving = 100;
         }
         enterToContinue();

        }
         
    


    void enterToContinue(){
        cout << "\nPress Enter to continue.\n";
            cin.ignore();
            cin.get();

    }
            

    void playerInfo(){
        
        
        
        cout << "\n================= PLAYER INFO =================\n"
                 << "| Name       : " << name << "\n"
                 << "| Gender     : " << gender << "\n"
                 << "| Strong Foot: " << strongFoot << "\n"
                 << "| Shoot Power: " << shotPower << "\n"
                 << "| Accuracy:  : " << accuracy << "\n"
                 << "| Diving:    : " << diving << "\n"
                 << "| Budget     : " << budget << "\n"
                 << "==============================================\n\n";

                 enterToContinue();
        }


        
    //   void staminaDecrease(int amount){
    //         stamina -= amount;



    //     }
      

      void statsDisplay(){
        cout << "\n=========== 📊 PLAYER STATS 📊 ===========\n"
             << "🧬 Shoot Power: " << shotPower << "\n"
             << "Accuracy: " << accuracy << '\n'
             << "Diving: " << diving << '\n'
             << "💰 Budget : $" << budget << "\n"
             << "==========================================\n";
      }

      void increaseStamina(){
       char option;
       cout << "\n=========== ⚡ BOOST SHOP ⚡ ===========\n"
         << "Current Shoot Power: " << shotPower << "   |   Budget: $" << budget << "\n"
         << "Current Accuracy: " << accuracy << "       |   Budget: $" << budget << "\n"
         << "Current Diving: " << diving << "           |   Budget: $" << budget << "\n"
         << "----------------------------------------\n"
         << "[B] Banana 🍌 | +20 Shot Power | -$20\n"
         << "[A] Apple 🍎 | +20 Accuracy   | -$20\n"
         << "[P] Protein Bar 💪 | +20 Diving | -$20\n"
         << "----------------------------------------\n"
         << "Choose your snack (B/A/P): ";
            cin >> option;

        if(option == 'B'){
            shotPower += 20;
            budget -= 20;
            statsDisplay();
        }    

        else if(option == 'A'){
            accuracy += 20;
            budget -= 20;
            statsDisplay();
        }

        else if(option == 'P'){
            diving += 20;
            budget -= 20;
            statsDisplay();
        }

        else {
            cout << "Invalid input. Try again.\n";
            cin >> option;
        }


        
            

      }
    
};


//---------- Game Setup ----------
string introduction(string name);

//---------- Display / Output ---------
void displayGoal(int &round);
void scoreBoard(int &playerScore, int &compScore, bool &userTurn);

//--------- Game logic / User Actions --------
bool userPenalty();
bool userGoalkeeper();

//---------- Function Definitions ----------



   // Function to return the introduction and rules as a string
string introduction(string name) {
    string intro = "Welcome to the Soccer Tournament Showdown, " + name + "!\n";
    intro += "In this penalty shootout game, players and the computer take turns attempting to score penalties.\n";
    intro += "The game follows these rules:\n\n";

    // Rule 1: 5 Penalties Each
    intro += "- 5 penalty shots for each team.\n";
    intro += "  Both you and the computer will get 5 shots each, alternating between shooter and goalkeeper.\n";
    intro += "  After 5 rounds, the team with the most goals wins the match.\n\n";

    // Rule 2: Boost Shop Between Games
    intro += "- Boost Shop Between Games.\n";
    intro += "  You will have access to a boost shop after each game to purchase items like bananas or chocolates.\n";
    intro += "  These items provide advantages such as helping with penalty shot success or giving minor boosts to the next game.\n\n";

    // Rule 3: Random Event Between Games
    intro += "- Random Event Between Games.\n";
    intro += "  A random event can take place between games. It could be something like:\n";
    intro += "    - Weather changes: rain or wind that affects accuracy.\n";
    intro += "    - Lucky break: a random boost to either your penalty shots or the opponent's.\n";
    intro += "    - Player injury: a temporary setback that reduces your stats for the next round.\n";
    intro += "    - Free Item: Get an extra item for your boost shop.\n";
    intro += "  These events add an element of unpredictability to the game, keeping things exciting!\n\n";

    // Rule 4: Lose and You're Out
    intro += "- Lose and You're Out.\n";
    intro += "  If you lose a match, you're out of the tournament. There are no second chances in this knockout-style competition.\n";
    intro += "  Win each game to advance to the next round until the final showdown!\n\n";

    // Closing statement
    intro += "These are the fundamental rules for the game. Now let's get into the exciting part: the gameplay!\n\n";

    return intro;
}





void displayGoal(int &round){
   
   cout << "Round: " << round << '\n'; 
   round ++;

    string goalFrame[7] ={   " _____________",
                            "|      O      |",
                            "|    /|||\\    |",
                            "|   # ||| #   |",
                            "|    /   \\    |",
                            "|   /     \\   |",
                            "|  #       #  |",
                        };
    for(int i = 0; i < 7; i++ ){
        cout << goalFrame[i];    
        cout << '\n';
    }


}



bool userPenalty(){
 string options = "LRM";
 char computerChoice = options[rand() % options.length()]; // To pick a random char
 char yourChoice;
    
    cout << "Pick where to shoot: (L, R, M): \n";
    cin >> yourChoice;

    while (yourChoice != 'L' && yourChoice != 'M' && yourChoice != 'R') {
        cout << "Invalid input. Enter L, M, or R: ";
        cin >> yourChoice;
    }
    
    

    if (yourChoice != computerChoice){
        
        return true;
    }

    else{

    return false;
    }
}

bool userGoalkeeper(){

    string options = "LRM";
    char computerChoice = options[rand() % options.length()]; // To pick a random char
    char yourChoice;


        cout << "Pick where to dive: (L, R, M): \n";
        cin >> yourChoice;
        
        while (yourChoice != 'L' && yourChoice != 'M' && yourChoice != 'R') {
            cout << "Invalid input. Enter L, M, or R: ";
            cin >> yourChoice;
        }
        
    
        if (yourChoice == computerChoice){
            
            return true;
        }
    
        else{
    
        return false;
        }
    
}



    void scoreBoard(int &playerScore, int &compScore, bool &userTurn, int &playerAttempt, int &compAttempt){
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
    
        // Scoreboard Display
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

        void nextLevel(int &level){
            
            level ++;     
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
                                "Hold your head high. There’s always a next time.\n" 
                                "Thanks for playing!\n" 
                                "\nPress Enter to exit.\n";
                                 cin.ignore();
                                 cin.get();
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
            cout << "🎉 You didn’t just play the game… you OWNED it.\n\n";
            
            cout << "This isn’t just a win. This is LEGENDARY.\n";
            cout << "🏆 The trophy is yours. You are the champion of the world. 🏆\n";
        
            cout << "\nPress Enter to lift the trophy...\n";
            cin.ignore();
            cin.get();
        }
        

        void draw(int &playerScore, int &compScore, bool &userTurn, int &playerAttempt, int &compAttempt, int &round){
        cout << "\n================ ⚠️ SUDDEN DEATH ⚠️ ================\n"
             << "🤯 It's all tied after 5 penalties each!\n"
             << "💥 Next goal could win it. Next miss could end it.\n"
             << "🧠 Stay sharp. 💪 Stay strong. 🎯 It's sudden death time!\n"
             << "=====================================================\n\n";

        displayGoal(round);
        scoreBoard(playerScore, compScore, userTurn, playerAttempt, compAttempt);
        


    }
        
    
        



    
    
    
    
     



  
    












//--------- Main ----------    
int main(){
srand(time(0));

int playerScore = 0;
int compScore = 0;
int stamina;
int budget;
bool userTurn; 
bool gameOn = true;
string name;
string gender;
string strongFoot;
int round = 1;
int playerAttempt = 0;
int compAttempt = 0;
int level = 1;





 
cout << "Name: \n";
        getline(cin, name);
        cout << "Gender: \n";
        getline(cin,gender);
        cout << "Strong foot: \n";
        getline (cin,strongFoot);  







soccerPlayer player(name, gender, strongFoot);
player.playerInfo();



for(char ch : introduction(name)){
    cout << ch << flush;
    this_thread::sleep_for(chrono::milliseconds(20));
}
displayBracket(level);


while(gameOn){
   

   
    playerAttempt = 0;
    compAttempt = 0;
    round = 0;
    playerScore = 0;
    compScore = 0;
   
    
    
    
    

      while(playerAttempt < 6 && compAttempt < 6){
         
         if(playerAttempt == 5 && compAttempt == 5){
            break;
    
            }
             
            if(level == 6){
            displayBracket(level);
            winningChampionMessage();
            
       }
             displayGoal(round);
    
             scoreBoard(playerScore, compScore, userTurn, playerAttempt, compAttempt);
             //Pefect place to add something between every penalty
             player.statsDisplay();
            
    }
    
    if(playerScore == compScore){
    bool noWinner = true;

    while(noWinner){
        draw(playerScore, compScore, userTurn, playerAttempt, compAttempt, round);

        if(playerAttempt == compAttempt && playerScore != compScore)
        break;
        
    }
    }

    if(playerScore > compScore){
        int randomNumber = rand() % 9;
        nextLevel(level);
        
        // for(char ch : player.rand(randomNumber)){
        //     cout << ch << flush;
        //     this_thread::sleep_for(chrono::milliseconds(500));
        // }
        player.rand(randomNumber);
     

        player.increaseStamina();
    }
    else {
        gameOn = false;
        break;
    }

    

    }

    
    
    
    

    
    

    
   for(char a : gameOverMessage()){
    cout << a << flush;
    this_thread::sleep_for(chrono::milliseconds(50));
   }
}

    




    
    









