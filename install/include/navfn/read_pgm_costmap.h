
#ifndef READ_PGM_COSTMAP_H
#define READ_PGM_COSTMAP_H

// <raw> is true for ROS-generated raw cost maps
COSTTYPE *readPGM(const char *fname, int *width, int *height, bool raw = false);

#endif // READ_PGM_COSTMAP_H
