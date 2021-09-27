#include "larpandora/LArPandoraInterface/LArPandoraDetectorType.h"

#include "larcore/Geometry/Geometry.h"

namespace lar_pandora{

    class DUNEFarDetVDThreeView : public LArPandoraDetectorType {
    public:
        float TargetViewU() const override {return 0.f; };
        float TargetViewV() const override {return 0.f; };
        float TargetViewW() const override {return 0.f; };
        float WirePitch(const geo::View_t view) const override {return 0.f; };
        float WireAngle(const geo::View_t view, const int tpc, const int cstat) const override {return 0.f; };
        bool ShouldSwitchUV(const unsigned int tpc, const unsigned int cstat) const override {return false; };
        void LoadDetectorGaps(LArDetectorGapList& listOfGaps) override {return; }; 
    };
}

