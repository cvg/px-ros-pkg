#######################################################################
#                     Image acquisition info                          #
#######################################################################

# Time of image acquisition, camera coordinate frame ID
Header header    # Header timestamp should be acquisition time of image
                 # Header frame_id should be optical frame of camera
                 # origin of frame should be optical center of camera
                 # +x should point to the right in the image
                 # +y should point down in the image
                 # +z should point into the plane of the image


#######################################################################
#                      Calibration Parameters                         #
#######################################################################
# These are fixed during camera calibration. Their values will be the #
# same in all messages until the camera is recalibrated. Note that    #
# self-calibrating systems may "recalibrate" frequently.              #
#######################################################################

# The camera model used.
string camera_model

# The name of the camera.
string camera_name

# The type of the camera.
string camera_type

# The image dimensions with which the camera was calibrated. Normally
# this will be the full camera resolution in pixels.
uint32 image_width
uint32 image_height

# The distortion parameters, size depending on the distortion model.
float64[] D

# The projection parameters, size depending on the projection model.
float64[] P

# Other parameters which are not defined by either the distortion or
# projection model.
float64[] M

# Pose of camera with respect to a specific reference frame.
geometry_msgs/Pose pose