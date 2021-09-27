#include "larpandora/LArPandoraInterface/LArPandoraDetectorType.h"

namespace lar_pandora{

    LArPandoraDetectorType *LArPandoraDetectorType::GetDetectorType()
    {
        art::ServiceHandle<geo::Geometry const> geo;

        const unsigned int nPlanes(geo->MaxPlanes());
        std::unordered_set<geo::_plane_proj> planeSet;
        for (unsigned int iPlane = 0; iPlane < nPlanes; ++iPlane)
          (void)planeSet.insert(geo->TPC(0, 0).Plane(iPlane).View());

        /*
        if (nPlanes == 3 && planeSet.count(geo::kU) && planeSet.count(geo::kV) && planeSet.count(geo::kW))
            return new DUNEFarDetHD; 

        else*/ if (nPlanes==3 && planeSet.count(geo::kU) && planeSet.count(geo::kY) && planeSet.count(geo::kZ))
            return new DUNEFarDetVDThreeView;

        throw cet::exception("LArPandora")
            << "LArPandoraDetectorType::GetDetectorType --- unable to determine the detector type from the geometry GDML";
    }


    /*
    bool DUNEFarDetHD::ShouldSwitchUV()
    {
        std::cout<<"I am HD"<<std::endl;
        return true;
    }
    */

    /*
    bool DUNEFarDetVDThreeView::ShouldSwitchUV() const
    {
        std::cout<<"I am VD"<<std::endl;
        return true;
    }
    */
}

