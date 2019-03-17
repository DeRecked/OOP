#pragma once

#include <iosfwd>
#include <vector>

class Map {
    public:

    // Default constructor to build map
    // Height and width default to 60 and 100
    Map(int h=60, int w=100)
        : height(h), width(w) 
    { resize_map(); }

    // Accessors
    int get_height() { return this->height; }
    int get_width() { return this->width; }
    int get_size() { return this->map_size; }
    int get_num_cities() { return this->num_cities; }

    // Mutators
    void set_height(const int h) { this->height = h; resize_map(); }
    void set_width(const int w) { this->width = w; resize_map(); }

    private:
    
    // Resize map vector and add features
    void resize_map();
    void populate_map();
    void populate_player_map();         // Player and computer maps are covered in fog of war
    void populate_computer_map();       // and will only show details that have been discovered

    // Map icons
    const char fow = '\0';
    const char land = '+';
    const char sea = '.';
    const char city = '*';
    const char army = 'A';
    const char fighter = 'F';
    const char patrol = 'P';
    const char destroyer = 'D';
    const char submarine = 'S';
    const char transport = 'T';
    const char carrier = 'C';
    const char battleship = 'B';
    const char satellite = 'Z';

    // Map properties
    int height;
    int width;
    int map_size;
    int num_cities;

    std::vector<std::vector<char>> computer_map;    // Map the computer sees
    std::vector<std::vector<char>> master_map;      // Entire map with all features
    std::vector<std::vector<char>> player_map;      // Map the user sees
};