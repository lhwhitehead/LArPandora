#include "larpandora/LArPandoraInterface/Detectors/DUNEFarDetVDThreeView.h"

namespace lar_pandora{
    DUNEFarDetVDThreeView::DUNEFarDetVDThreeView() 
    {}
    
    geo::View_t DUNEFarDetVDThreeView::TargetViewU() const
    {
        const bool isDualPhase(m_LArSoftGeometry->MaxPlanes() == 2);
        std::cout<<"are we dual phase: " << isDualPhase << std::endl;
        return (isDualPhase ? geo::kW : geo::kU);
    }
}

