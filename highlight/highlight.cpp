#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Variables for the rectangle selection
Point topLeft, bottomRight;
bool drawing = false;          // Flag to track the drawing status
bool rectangleSelected = false; // Flag to indicate selection is completed

// Callback function for mouse events
void mouseCallback(int event, int x, int y, int, void* userdata) {
    Mat* image = static_cast<Mat*>(userdata);

    switch (event) {
        case EVENT_LBUTTONDOWN: // Start drawing the rectangle
            drawing = true;
            rectangleSelected = false;
            topLeft = Point(x, y);
            break;
        case EVENT_MOUSEMOVE: // Update the rectangle while moving the mouse
            if (drawing) {
                bottomRight = Point(x, y);
                Mat temp = image->clone();
                rectangle(temp, topLeft, bottomRight, Scalar(255), 1); // Show rectangle
                imshow("Image", temp);
            }
            break;
        case EVENT_LBUTTONUP: // Finalize the rectangle
            drawing = false;
            rectangleSelected = true;
            bottomRight = Point(x, y);

            // Redraw the original image to ensure no rectangle remains
            imshow("Image", *image);
            break;
    }
}

int main(int argc, char** argv) {
    // Define the command-line parser
    const String keys =
        "{@image    |      | Path to the grayscale image file (required)}"
        "{help h    |      | Show help message}";

    CommandLineParser parser(argc, argv, keys);

    // Show help if needed
    if (parser.has("help") || !parser.check()) {
        parser.printMessage();
        return 0;
    }

    // Get the image path
    String imagePath = parser.get<String>(0);
    if (imagePath.empty()) {
        cerr << "Error: Image path not provided." << endl;
        return -1;
    }

    // Load the image in grayscale
    Mat image = imread(imagePath, IMREAD_GRAYSCALE);
    if (image.empty()) {
        cerr << "Error: Unable to load the image." << endl;
        return -1;
    }

    // Display the image and set the mouse callback
    namedWindow("Image", WINDOW_AUTOSIZE);
    setMouseCallback("Image", mouseCallback, &image);

    imshow("Image", image);

    // Wait for the user to select a rectangle
    while (true) {
        int key = waitKey(1);
        if (key == 27 || rectangleSelected) // Escape key or selection completed
            break;
    }

    if (!rectangleSelected) {
        cout << "No rectangle was selected. Exiting." << endl;
        return 0;
    }

    // Ensure proper ordering of the rectangle coordinates
    int x1 = min(topLeft.x, bottomRight.x);
    int y1 = min(topLeft.y, bottomRight.y);
    int x2 = max(topLeft.x, bottomRight.x);
    int y2 = max(topLeft.y, bottomRight.y);

    // Define the ROI
    Rect roi(x1, y1, x2 - x1, y2 - y1);

    // Dim the entire image
    Mat dimmedImage;
    image.convertTo(dimmedImage, -1, 0.75);

    // Extract and equalize the ROI
    Mat roiImage = image(roi);
    Mat equalizedROI;
    equalizeHist(roiImage, equalizedROI);

    // Replace the ROI in the dimmed image with the equalized ROI
    equalizedROI.copyTo(dimmedImage(roi));

    // Close the original image window
    destroyWindow("Image");

    // Display the result
    imshow("Highlighted Image", dimmedImage);
    waitKey(0);

    return 0;
}
