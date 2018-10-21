#ifndef MANEUVER__VISIBILITY_CONTROL_H_
#define MANEUVER__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define MANEUVER_EXPORT __attribute__ ((dllexport))
    #define MANEUVER_IMPORT __attribute__ ((dllimport))
  #else
    #define MANEUVER_EXPORT __declspec(dllexport)
    #define MANEUVER_IMPORT __declspec(dllimport)
  #endif
  #ifdef MANEUVER_BUILDING_LIBRARY
    #define MANEUVER_PUBLIC MANEUVER_EXPORT
  #else
    #define MANEUVER_PUBLIC MANEUVER_IMPORT
  #endif
  #define MANEUVER_PUBLIC_TYPE MANEUVER_PUBLIC
  #define MANEUVER_LOCAL
#else
  #define MANEUVER_EXPORT __attribute__ ((visibility("default")))
  #define MANEUVER_IMPORT
  #if __GNUC__ >= 4
    #define MANEUVER_PUBLIC __attribute__ ((visibility("default")))
    #define MANEUVER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MANEUVER_PUBLIC
    #define MANEUVER_LOCAL
  #endif
  #define MANEUVER_PUBLIC_TYPE
#endif

#endif  // MANEUVER__VISIBILITY_CONTROL_H_
