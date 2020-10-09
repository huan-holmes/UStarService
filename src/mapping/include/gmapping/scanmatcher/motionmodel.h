#ifndef _MOTIONMODEL_H_
#define _MOTIONMODEL_H_

#include "gmapping/utils/point.h"
#include "gmapping/utils/stat.h"
#include "gmapping/utils/macro_params.h"

namespace UstarSlam
{

	struct MotionModel
	{
		OrientedPoint drawFromMotion(const OrientedPoint &p, double linearMove, double angularMove) const;
		OrientedPoint drawFromMotion(const OrientedPoint &p, const OrientedPoint &pnew, const OrientedPoint &pold) const;
		Covariance3 gaussianApproximation(const OrientedPoint &pnew, const OrientedPoint &pold) const;
		double srr, str, srt, stt;
	};

}; // namespace UstarSlam

#endif
