//
//  main.cpp
//  ECU
//
//  Created by Pranav Saravanan.
//

#include <iostream>

class ECU
{
private:
    // Boolean variables to track the state of each feature
    bool m_bHydraulicJacks;
    bool m_bInfraredLights;
    bool m_bGripTires;
    bool m_bAutoJack;
    
    // Private member function to handle the hydraulic jacks
    void handleHydraulicJacks()
    {
        m_bHydraulicJacks = !m_bHydraulicJacks;
        std::cout << "Hydraulic Jacks: " << (m_bHydraulicJacks ? "Activated" : "Deactivated") << std::endl;
    }
    
    // Private member function to handle the infrared driving lights
    void handleInfraredLights()
    {
        m_bInfraredLights = !m_bInfraredLights;
        std::cout << "Infrared Lights: " << (m_bInfraredLights ? "Activated" : "Deactivated") << std::endl;
    }
    
    // Private member function to handle the special grip tires
    void handleGripTires()
    {
        // If the auto-jack is activated, deactivate the grip tires
        if (m_bAutoJack)
        {
            m_bGripTires = false;
            std::cout << "Grip Tires: Deactivated (Auto-Jack activated)" << std::endl;
        }
        else
        {
            m_bGripTires = !m_bGripTires;
            std::cout << "Grip Tires: " << (m_bGripTires ? "Activated" : "Deactivated") << std::endl;
        }
    }
    
    // Private member function to handle the auto-jack
    void handleAutoJack()
    {
        // If the grip tires are activated, deactivate the auto-jack
        if (m_bGripTires)
        {
            m_bAutoJack = false;
            std::cout << "Auto-Jack: Deactivated (Grip Tires activated)" << std::endl;
        }
        else
        {
            m_bAutoJack = !m_bAutoJack;
            std::cout << "Auto-Jack: " << (m_bAutoJack ? "Activated" : "Deactivated") << std::endl;
        }
    }
    
public:
    // Default constructor
    ECU()
    {
        // Initialize the feature states to false (deactivated)
        m_bHydraulicJacks = false;
        m_bInfraredLights = false;
        m_bGripTires = false;
        m_bAutoJack = false;
    }
    
    // Class destructor
    ~ECU() {};
    
    // Public member function to handle user commands
    void handleCommand(char command)
    {
      // Use a switch statement to handle the command
      switch (command)
      {
        case 'A':
          handleHydraulicJacks();
          break;
        case 'B':
          handleInfraredLights();
          break;
        case 'C':
          handleGripTires();
          break;
        case 'D':
          handleAutoJack();
          break;
        default:
          std::cout << "Invalid command." << std::endl;
          break;
      }
    }
};
