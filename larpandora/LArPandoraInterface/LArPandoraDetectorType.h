#include "larcore/Geometry/Geometry.h"

namespace lar_pandora{

    class DetectorType {
    public:
        static DetectorType *GetDetectorType(art::ServiceHandle<geo::Geometry const> geo);
        pure virtual bool FlipViews();
    };

    class DUNEFarDetHD : public DetectorType {
    public:
        bool FlipViews() override;
    };

    class DUNEFarDetVDThreeView : public DetectorType {
    public:
        bool FlipViews() override;
    };

}
