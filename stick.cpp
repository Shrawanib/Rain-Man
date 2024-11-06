#include <graphics.h>  // Include graphics library

// Function to draw stickman with legs open
void stickman_open(int a, int um_out, int um_color, int um_pattern)
{
    for (int i = 0; i < 3; i++) // Loop to add thickness to the drawing
    {
        setcolor(YELLOW); // Set color for head and body
        circle(50 + a, 320, 30 + i); // Draw head
        line(50 + i + a, 350, 50 + i + a, 400); // Draw body

        // Draw legs in open position
        line(50 + i + a, 400, 30 + i + a, 450); // Left leg
        line(50 + i + a, 400, 70 + i + a, 450); // Right leg

        // Draw right arm
        line(50 + a + i, 360, 20 + a + i, 400);

        // Draw left arm and additional details
        line(50 + a, 360 + i, 80 + a, 380 + i); // Upper arm
        line(80 + i + a, 380, 100 + i + a, 360); // Lower arm

        setcolor(um_out); // Set outline color for umbrella
        line(100 + i + a, 360, 100 + i + a, 270); // Draw umbrella handle
        line(50 + a, 270 + i, 150 + a, 270 + i); // Draw umbrella top
        arc(100 + a, 270, 0, 180, 50 + i); // Draw umbrella arc

        setfillstyle(um_pattern, um_color); // Set fill pattern and color
        floodfill(100 + a, 260, um_out); // Fill umbrella with color
    }
}

// Function to draw stickman with legs closed
void stickman_close(int a, int um_out, int um_color, int um_pattern)
{
    for (int i = 0; i < 3; i++) // Loop to add thickness
    {
        setcolor(YELLOW); // Set color for head and body
        circle(50 + a, 320, 30 + i); // Draw head
        line(50 + i + a, 350, 50 + i + a, 400); // Draw body

        // Draw legs in closed position
        line(50 - i + a, 400, 50 - i + a, 450); // Left leg
        line(50 + i + a, 400, 50 + i + a, 450); // Right leg

        // Draw right arm
        line(50 + a + i, 360, 45 + a + i, 400);

        // Draw left arm and additional details
        line(50 + a, 360 + i, 80 + a, 380 + i); // Upper arm
        line(80 + i + a, 380, 100 + i + a, 360); // Lower arm

        setcolor(um_out); // Set outline color for umbrella
        line(100 + i + a, 360, 100 + i + a, 270); // Draw umbrella handle
        line(50 + a, 270 + i, 150 + a, 270 + i); // Draw umbrella top
        arc(100 + a, 270, 0, 180, 50 + i); // Draw umbrella arc

        setfillstyle(um_pattern, um_color); // Set fill pattern and color
        floodfill(100 + a, 260, um_out); // Fill umbrella with color
    }    
}

// Function to draw raindrops
void rain()
{
    setcolor(LIGHTCYAN); // Set color for rain

    for (int i = 0; i < 60; i++) // Loop for multiple raindrops
    {
        settextstyle(0, HORIZ_DIR, 2); // Set text style for raindrop symbol
        outtextxy(rand() % 600, rand() % 445, "| "); // Draw raindrop at random position
    }
    setcolor(WHITE); // Reset color to white
}

// Function to draw road line
void road(void)
{
    setcolor(LIGHTMAGENTA); // Set color for road
    for (int i = 0; i < 3; i++) // Loop to add thickness
    {
        line(0, 450 + i, 600, 450 + i); // Draw road line
    }
    setcolor(WHITE); // Reset color to white
}

// Driver program
int main()
{
    int s = 0; // Position variable for horizontal movement
    initwindow(600, 500, "Stickman", 150, 50); // Initialize graphics window
    int page = 0; // Page variable for double buffering
    int n = 0; // Frame counter

    while (n <= 150) // Animation loop for 150 frames
    {
        setactivepage(page); // Set active page for drawing
        setvisualpage(1 - page); // Set visible page for display
        cleardevice(); // Clear screen

        road(); // Draw road
        rain(); // Draw rain

        if (n % 2 == 0) // Alternate between open and closed legs
            stickman_open(s, 9, 9, 3); // Draw stickman with legs open
        else
            stickman_close(s, 9, 9, 3); // Draw stickman with legs closed

        page = 1 - page; // Toggle page for double buffering
        delay(150); // Delay for animation speed
        s += 4; // Move stickman horizontally

        n++; // Increment frame counter
    }

    getch(); // Wait for key press
    closegraph(); // Close graphics mode
}

