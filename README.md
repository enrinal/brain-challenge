# brain-challenge
Brain Challange is a memorizing game. Project For Algorithm and Data Structure Course

To Compile : gcc brain.c game.c game.h listsingle.c listsingle.h boolean.h -o brain

In "Brain Challange" is given a game that will emphasize the process of player memory. The rules of play in this game are the players are required to remember the number of symbols * appearing in a given scene, which each scene allows for the emergence of 15 symbols between +, -, /, *,%, and $ symbols. At the beginning of the game, given 3 scenes each containing 15 symbols, and each new scene, the old scene will be removed from view. Every scene, players are given 5 seconds to count and remember the number * that appears.

After starting with 3 scenes, players are asked how many "*" numbers appear in the first scene. When the answer given is wrong, then the game will end as well as displayed the number of successfully answered scenes the number * that appears. But if the answer given is correct, the player will be given the next scene and given 5 seconds back to count and remember, and proceed by asking the number * in the second scene. The process will continue to recur as long as the player continues to recur as long as the player continues to provide correct answers. There are three stages that can be passed by the player. Stage 1 is an easy stage, the stage is displayed 15 random symbols and 5 seconds recall time, stage 2 is a medium stage, the player will enter on this stage when it has reached the 15th scene, the stage is displayed 15 random symbols and remembering time for 3 seconds, and the last stage 3, stage 3 is a difficult stage, the player will enter on this stage when it comes to the 30th scene, in this stage is displayed 20 random symbols and a recall time for 3 seconds.
