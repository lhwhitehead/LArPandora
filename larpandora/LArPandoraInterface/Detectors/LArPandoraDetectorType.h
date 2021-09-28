#ifndef LAR_PANDORA_DETECTOR_TYPE_H
#define LAR_PANDORA_DETECTOR_TYPE_H 1


#include "larcore/Geometry/Geometry.h"

namespace lar_pandora{

    class LArDetectorGap;
    typedef std::vector<LArDetectorGap> LArDetectorGapList;

    class LArPandoraDetectorType {
    public:
        virtual geo::View_t TargetViewU() const = 0;
        virtual geo::View_t TargetViewV() const = 0;
        virtual geo::View_t TargetViewW() const = 0;
        virtual float WirePitch(const geo::View_t view) const = 0;
        virtual float WireAngle(const geo::View_t view, const int tpc, const int cstat) const = 0;
        virtual bool ShouldSwitchUV(const unsigned int tpc, const unsigned int cstat) const = 0;
        virtual void LoadDetectorGaps(LArDetectorGapList& listOfGaps) = 0;
    };

    LArPandoraDetectorType *GetDetectorType();
}
#endif
