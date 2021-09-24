#include "larcore/Geometry/Geometry.h"

namespace lar_pandora{

    class LArPandoraDetectorType {
    public:
        static LArPandoraDetectorType *GetDetectorType();
        virtual bool ShouldSwitchUV() = 0;
    };

    class DUNEFarDetHD : public LArPandoraDetectorType {
    public:
        bool ShouldSwitchUV() override;
    };

    class DUNEFarDetVDThreeView : public LArPandoraDetectorType {
    public:
        bool ShouldSwitchUV() override;
    };

}
