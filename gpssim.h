// This file is part of:
// gnss-sim: A GNSS Signal Simulator
//
// Copyright (c) 2020 Damien Dusha
// SPDX-License-Identifier: MIT
//
// Derived from https://github.com/osqzss/gps-sdr-sim (MIT Licence):
// Copyright (c) 2015-2020 Takuji Ebinuma

#ifndef GPSSIM_H
#define GPSSIM_H

#include "geodesy.h"
#include "gps_time.h"

/*! \brief Maximum number of satellites in RINEX file */
#define MAX_SAT (32)

/*! \brief Maximum number of channels we simulate */
#define MAX_CHAN (16)

/*! \brief Maximum duration for static mode*/
#define STATIC_MAX_DURATION (86400) // second

/*! \brief Number of subframes */
#define N_SBF (5) // 5 subframes per frame

/*! \brief Number of words per subframe */
#define N_DWRD_SBF (10) // 10 word per subframe

/*! \brief Number of words */
#define N_DWRD ((N_SBF+1)*N_DWRD_SBF) // Subframe word buffer size

/*! \brief C/A code sequence length */
#define CA_SEQ_LEN (1023)

#define SECONDS_IN_WEEK 604800.0
#define SECONDS_IN_HALF_WEEK 302400.0
#define SECONDS_IN_HOUR 3600.0
#define SECONDS_IN_MINUTE 60.0

// Conventional values employed in GPS ephemeris model (ICD-GPS-200)
#define GM_EARTH 3.986005e14
#define OMEGA_EARTH 7.2921151467e-5
#define PI 3.1415926535898

#define WGS84_RADIUS	6378137.0
#define WGS84_ECCENTRICITY 0.0818191908426

#define R2D 57.2957795131

#define SPEED_OF_LIGHT 2.99792458e8

/*! \brief GPS L1 Carrier frequency */
#define CARR_FREQ (1575.42e6)

/*! \brief C/A code frequency */
#define CODE_FREQ (1.023e6)
#define CARR_TO_CODE (1.0/1540.0)

#define EPHEM_ARRAY_SIZE (13) // for daily GPS broadcast ephemers file (brdc)

struct range_t
{
	gpstime_t g;
	double range; // pseudorange
	double rate;
	double d; // geometric distance
	AzimuthElevation azel;
	double iono_delay;
};

#endif
