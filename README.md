# OpencvSetupMacOS
A opencv setup project in Xcode, as of macOS 10.14.3, OpenCv 4.0.1


# Setup Steps

1. Install Xcode
2. Install Homebrew
3. Install OpenCV with Homebrew in terminal
    "brew install opencv"
4. Install pkg-config
    "bew install pkg-config"
5. View OpenCV linker flags for Xcode setup
    "pkg-config --cflags --libs opencv"
    in case of "Package opencv was not found in the pkg-config search path...":
        "pkg-config --cflags --libs path/to/opencv.pc"
        My "path/to/opencv.pc" is "/usr/local/Cellar/opencv/4.0.1/lib/pkgconfig/opencv4.pc"
    copy the output of the pkg-config command:
        My output: "-I/usr/local/Cellar/opencv/4.0.1/include/opencv4/opencv -I/usr/local/Cellar/opencv/4.0.1/include/opencv4 -L/usr/local/Cellar/opencv/4.0.1/lib -lopencv_gapi -lopencv_stitching -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dpm -lopencv_face -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_line_descriptor -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_dnn -lopencv_plot -lopencv_videostab -lopencv_video -lopencv_xfeatures2d -lopencv_shape -lopencv_ml -lopencv_ximgproc -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core"
6. Create a new Xcode command line tool project
    On the left column, click on the top blue project icon, then on the main window choose "Build Settings"
    One row down, choose "All" and "Combined", in the search bar:
      Search "header search paths": add "/usr/local/Cellar/opencv/4.0.1/include/opencv4"
      Search "library search paths": add "/usr/local/Cellar/opencv/4.0.1/lib"
      Search "other linker flags": add the output of step 5: "-I/usr/local/Cellar/opencv/4.0.1/include/opencv4/opencv -I/usr/local/Cellar/opencv/4.0.1/include/opencv4 -L/usr/local/Cellar/opencv/4.0.1/lib -lopencv_gapi -lopencv_stitching -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dpm -lopencv_face -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_line_descriptor -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_dnn -lopencv_plot -lopencv_videostab -lopencv_video -lopencv_xfeatures2d -lopencv_shape -lopencv_ml -lopencv_ximgproc -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core"
7. in the source files:
  "#include <opencv2/opencv.hpp>"
  "using namespace cv"


8. Optional setups
    1) Add image files to working directory:
        a. On the left column of the Xcode, right click on the project folder name, and click on "New Group" to create a working directory folder("Workdir" in my case).A workding directory folder will be created under the project folder.
        b. Move the image files to the working directory folder just created("wall1.tif" into "/Workdir" in my case).
        c. Right click on the working directory folder on the left column of Xcode and click on "Add Files...", then navigate to the actually location of the folder, since the image files are already added, choose them all and "Add". Now the image files should show up on the left column under the created new group("Workdir" in my case).
    2) Add a working directory folder( "Workdir" in my case) to project:
        Click on the Project Name right of the Stop button on the left up corner to show "Edit Scheme". Click on "Edit Scheme", in "Options" tab, choose "Working Driectory", and set the full path to the working directory just created.("/Users/zibin/Desktop/OpenCV_Start/OpenCV_Start/Workdir" in my case).    
    3) Add an argument when start the program:
        "Edit Scheme"->"Arguments" tab->"Arguments Passed On Launch"->add the argument("wall1.tif" in my case).
