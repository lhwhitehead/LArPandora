#include "larpandora/LArPandoraInterface/LArPandoraGeometry.h"

#include "larcore/Geometry/Geometry.h"

namespace lar_pandora{

    class LArPandoraDetectorType {
    public:
        LArPandoraDetectorType *GetDetectorType();
        virtual float TargetViewU() const = 0;
        virtual float TargetViewV() const = 0;
        virtual float TargetViewW() const = 0;
        virtual float WirePitch(const geo::View_t view) const = 0;
        virtual float WireAngle(const geo::View_t view, const int tpc, const int cstat) const = 0;
        virtual bool ShouldSwitchUV(const unsigned int tpc, const unsigned int cstat) const = 0;
        virtual void LoadDetectorGaps(LArDetectorGapList& listOfGaps) = 0;
    };

    LArPandoraDetectorType *GetDetectorType();

    /*
    class DUNEFarDetHD : public LArPandoraDetectorType {
    public:
        bool ShouldSwitchUV() const override;
    };
    */

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
