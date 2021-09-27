#include "larpandora/LArPandoraInterface/LArPandoraDetectorType.h"

#include "larcore/Geometry/Geometry.h"

namespace lar_pandora{

    class DUNEFarDetVDThreeView : public LArPandoraDetectorType {
    public:
        geo::View_t TargetViewU() const override {return geo::kUnknown; };
        geo::View_t TargetViewV() const override {return geo::kUnknown; };
        geo::View_t TargetViewW() const override {return geo::kUnknown; };
        float WirePitch(const geo::View_t view) const override {return 0.f; };
        float WireAngle(const geo::View_t view, const int tpc, const int cstat) const override {return 0.f; };
        bool ShouldSwitchUV(const unsigned int tpc, const unsigned int cstat) const override {return false; };
        void LoadDetectorGaps(LArDetectorGapList& listOfGaps) override {return; }; 
    };
}

