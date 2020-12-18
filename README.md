#problem
The inhabitants of a far off star system have developed a transportation system between their planets. There are n planets in the system. Some planets have a wormhole between them, which allows you to travel between planet i to planet j in ti; j seconds. All times ti; j are positive (you can’t travel back in time). Some pairs of planets may not have a wormhole between them.
You are currently at planet 0 and wish to reach planet n􀀀1. However, your ship’s navigation commands are starting to malfunction. 
When you are at a planet and tell the ship to go through a certain wormhole, it may misinterpret the command and instead choose a completely random outgoing wormhole instead. 
Luckily, you know that you that this will happen at most once. 
You don’t know when the malfunction might happen, but you are going to assume it will happen at the most inconvenient time.
You want to choose a strategy that will minimize your total travel time in the very worst case (no matter when the malfunction happens or which outgoing wormhole it takes you on). 
Design an efficient algorithm for this. Specifically, your algorithm should output at what time you can be guaranteed to reach planet n􀀀1, if we use the optimal strategy.
You don’t need to prove your algorithm correct or justify the stated running time. 
You may assume it’s possible to reach planet n􀀀1 from any other planet via some sequence of wormholes.
