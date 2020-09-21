#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/boocax/UstarService/src/planning/local_planner"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/boocax/UstarService/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/boocax/UstarService/install/lib/python2.7/dist-packages:/home/boocax/UstarService/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/boocax/UstarService/build" \
    "/usr/bin/python2" \
    "/home/boocax/UstarService/src/planning/local_planner/setup.py" \
    build --build-base "/home/boocax/UstarService/build/planning/local_planner" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/boocax/UstarService/install" --install-scripts="/home/boocax/UstarService/install/bin"
