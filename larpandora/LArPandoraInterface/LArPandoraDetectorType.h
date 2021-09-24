#include "larcore/Geometry/Geometry.h"

namespace lar_pandora{

    class LArPandoraDetectorType {
    public:
        static LArPandoraDetectorType *GetDetectorType();
        virtual float WirePitchU() const = 0;
        virtual float WirePitchV() const = 0;
        virtual float WirePitchW() const = 0;
        virtual bool ShouldSwitchUV() const = 0;
    };

    /*
    class DUNEFarDetHD : public LArPandoraDetectorType {
    public:
        bool ShouldSwitchUV() const override;
    };
    */

    class DUNEFarDetVDThreeView : public LArPandoraDetectorType {
    public:
        float WirePitchU() const override {return 0.f; };
        float WirePitchV() const override {return 0.f; };
        float WirePitchW() const override {return 0.f; };
        bool ShouldSwitchUV() const override;
    };

}
