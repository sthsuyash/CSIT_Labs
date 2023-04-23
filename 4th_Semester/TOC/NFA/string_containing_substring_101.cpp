#include <iostream>
#include <vector>

using namespace std;

// Define the NFA as a set of states and transitions
vector<int> states = {0, 1, 2, 3}; // States are represented by integers (0, 1, 2, ...)
vector<vector<pair<char, int>>> transitions = {
    {{'0', 0}, {'1', 0}, {'1', 1}},
    {{'0', 2}},
    {{'1', 3}},
    {{'0', 3}, {'1', 3}}}; // Transitions are represented by pairs of characters and states (character, state)

// Define a function to simulate the NFA on a given string
bool simulate_nfa(string input)
{
    // Start at the initial state (state 0)
    vector<int> current_states = {0};

    // Loop through each character in the input string
    for (char c : input)
    {
        // Find all possible transitions from the current states for the current character
        vector<int> next_states;
        for (int state : current_states)
        {
            for (auto transition : transitions[state])
            {
                if (transition.first == c)
                {
                    next_states.push_back(transition.second);
                }
            }
        }
        // If there are no possible transitions, the input string is not accepted
        if (next_states.empty())
        {
            return false;
        }
        // Update the current states to the next states
        current_states = next_states;
    }
    // If the final state is an accepting state, the input string is accepted
    for (int state : current_states)
    {
        if (state == 3)
        {
            return true;
        }
    }
    return false;
}

// Define the main function to run the program
int main()
{
    // Get input from the user
    string input;
    cout << "Enter a string to check: ";
    cin >> input;

    // Simulate the NFA on the input string and output the result
    if (simulate_nfa(input))
    {
        cout << "String contains substring 101." << endl;
    }
    else
    {
        cout << "String does not contain substring 101." << endl;
    }

    return 0;
}
