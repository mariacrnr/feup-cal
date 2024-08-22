# FlightNet: Optimization of Flight Routes
This project aims to create an optimized system for managing international flights between airports. The system is designed to enhance the efficiency of passenger transportation by determining the most effective routes for commercial flights operating in circular patterns, returning to their origin after multiple stops. It is structured into three main phases. The first phase addresses route optimization for a single aircraft, taking into account constraints such as fuel capacity and crew rotation to calculate the shortest path between the origin and destination airports, including necessary layovers. The second phase introduces multiple aircraft into the model, increasing complexity by ensuring all passengers are accommodated, albeit with potential route inefficiencies. The final phase focuses on route optimization to maximize profitability, possibly by eliminating less profitable routes or adjusting circular routes to cover additional stops. Key functionalities of the system include graph connectivity analysis, shortest path algorithms, and customizable constraints such as aircraft capacity and fuel limitations. The project also features an interface for route and airport visualization, leveraging various data structures and algorithms.

## List of Dependencies
* GraphViewer: To ease the visualization of our algorithms, we use the GraphViewer API to show the graph and it's 
relevant nodes
* Data Files: The algorithms work with edges and nodes of a directed graph that have a specific syntax. The files are
all in the data folder, as well as the background picture to show the graph on.

## Compilation Instructions
To compile and run our program, you only need to run the .exe file and the main menu with all the implemented 
functionalities will be shown.
