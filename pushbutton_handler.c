#include <stdint.h>
#include <stdbool.h>

// Define the GPIO register addresses
#define GPIO_START 0x00040100 // GPIO Start Address
#define GPIO_OFFSET 0x08      // Generic offset used to access GPIO registers

#define GPIO_DIRECTION_CNTRL_REG ((uint32_t*) (GPIO_START + (0 * GPIO_OFFSET)))
#define GPIO_DATA_REG ((uint32_t*) (GPIO_START + (1 * GPIO_OFFSET)))

// Define the GPIO pins
#define GPIO0  (1 << 0)
#define GPIO1  (1 << 1)
#define GPIO2  (1 << 2)
#define GPIO3  (1 << 3)
#define GPIO4  (1 << 4)
#define GPIO5  (1 << 5)
#define GPIO6  (1 << 6)
#define GPIO7  (1 << 7)
#define GPIO8  (1 << 8)
#define GPIO9  (1 << 9)
#define GPIO10 (1 << 10)
#define GPIO11 (1 << 11)
#define GPIO12 (1 << 12)
#define GPIO13 (1 << 13)
#define GPIO14 (1 << 14)
#define GPIO15 (1 << 15)
#define GPIO16 (1 << 16)
#define GPIO17 (1 << 17)
#define GPIO18 (1 << 18)
#define GPIO19 (1 << 19)
#define GPIO20 (1 << 20)
#define GPIO21 (1 << 21)
#define GPIO22 (1 << 22)
#define GPIO23 (1 << 23)
#define GPIO24 (1 << 24)
#define GPIO25 (1 << 25)
#define GPIO26 (1 << 26)
#define GPIO27 (1 << 27)
#define GPIO28 (1 << 28)
#define GPIO29 (1 << 29)
#define GPIO30 (1 << 30)
#define GPIO31 (1 << 31)
#define GPIO_COUNT 0x20

// Function prototypes
void GPIO_Init(void);
uint32_t Read_PushButton_Status(void);
uint32_t Debounce_PushButton(uint32_t button_status);
void Handle_PushButtons(void);

// Function to initialize GPIO for input
void GPIO_Init(void) {
    // Set the direction for GPIO17, GPIO28, GPIO04, and GPIO10 to input (0)
    *GPIO_DIRECTION_CNTRL_REG &= ~(GPIO17 | GPIO28 | GPIO4 | GPIO10);
}

// Function to read the status of the push buttons
uint32_t Read_PushButton_Status(void) {
    // Read the GPIO data register and mask the relevant bits
    return (*GPIO_DATA_REG) & (GPIO17 | GPIO28 | GPIO4 | GPIO10);
}

// Function to debounce push buttons
uint32_t Debounce_PushButton(uint32_t button_status) {
    static uint32_t last_button_status = 0;
    static uint32_t stable_button_status = 0;
    static uint32_t counter = 0;

    if (button_status == last_button_status) {
        if (counter < 5) { // Arbitrary debounce delay
            counter++;
        } else {
            stable_button_status = button_status;
        }
    } else {
        counter = 0;
    }

    last_button_status = button_status;
    return stable_button_status;
}

// Main function to handle push button states
void Handle_PushButtons(void) {
    while (1) {
        // Read the status of the push buttons
        uint32_t button_status = Read_PushButton_Status();
        
        // Debounce the button status
        button_status = Debounce_PushButton(button_status);

        // Handle each button status using switch-case
        switch (button_status) {
            case 0: // No button pressed
                // Handle no button pressed
                break;

            case GPIO17: // GPIO17 (Button 1) pressed
                // Handle GPIO17 pressed
                break;

            case GPIO28: // GPIO28 (Button 2) pressed
                // Handle GPIO28 pressed
                break;

            case GPIO4: // GPIO4 (Button 3) pressed
                // Handle GPIO4 pressed
                break;

            case GPIO10: // GPIO10 (Button 4) pressed
                // Handle GPIO10 pressed
                break;

            case (GPIO17 | GPIO28): // GPIO17 and GPIO28 pressed
                // Handle GPIO17 and GPIO28 pressed
                break;

            case (GPIO17 | GPIO4): // GPIO17 and GPIO4 pressed
                // Handle GPIO17 and GPIO4 pressed
                break;

            case (GPIO17 | GPIO10): // GPIO17 and GPIO10 pressed
                // Handle GPIO17 and GPIO10 pressed
                break;

            case (GPIO28 | GPIO4): // GPIO28 and GPIO4 pressed
                // Handle GPIO28 and GPIO4 pressed
                break;

            case (GPIO28 | GPIO10): // GPIO28 and GPIO10 pressed
                // Handle GPIO28 and GPIO10 pressed
                break;

            case (GPIO4 | GPIO10): // GPIO4 and GPIO10 pressed
                // Handle GPIO4 and GPIO10 pressed
                break;

            case (GPIO17 | GPIO28 | GPIO4): // GPIO17, GPIO28, and GPIO4 pressed
                // Handle GPIO17, GPIO28, and GPIO4 pressed
                break;

            case (GPIO17 | GPIO28 | GPIO10): // GPIO17, GPIO28, and GPIO10 pressed
                // Handle GPIO17, GPIO28, and GPIO10 pressed
                break;

            case (GPIO17 | GPIO4 | GPIO10): // GPIO17, GPIO4, and GPIO10 pressed
                // Handle GPIO17, GPIO4, and GPIO10 pressed
                break;

            case (GPIO28 | GPIO4 | GPIO10): // GPIO28, GPIO4, and GPIO10 pressed
                // Handle GPIO28, GPIO4, and GPIO10 pressed
                break;

            case (GPIO17 | GPIO28 | GPIO4 | GPIO10): // All buttons pressed
                // Handle all buttons pressed
                break;

            default:
                // Handle unexpected cases
                break;
        }
    }
}

int main(void) {
    // Initialize GPIO
    GPIO_Init();

    // Handle push buttons
    Handle_PushButtons();

    return 0;
}
