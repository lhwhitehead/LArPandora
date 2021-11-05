#include "larpandora/LArPandoraInterface/Detectors/VintageLArTPCThreeView.h"
#include "larpandora/LArPandoraInterface/LArPandoraGeometry.h"

#include "larcore/Geometry/Geometry.h"

namespace lar_pandora{

    class ICARUS : public VintageLArTPCThreeView {
    public:
        geo::View_t TargetViewU(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const override;
        geo::View_t TargetViewV(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const override;
        geo::View_t TargetViewW(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const override;
        float WireAngleW(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const override;
    private:
        art::ServiceHandle<geo::Geometry> m_LArSoftGeometry;
    };

    inline geo::View_t ICARUS::TargetViewU(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const
    {
        return (m_LArSoftGeometry->TPC(tpc, cstat).DriftDirection() == geo::kPosX ?
                    m_LArSoftGeometry->View(geo::PlaneID(cstat, tpc, 2)) :
                    m_LArSoftGeometry->View(geo::PlaneID(cstat, tpc, 1)));
    }

    inline geo::View_t ICARUS::TargetViewV(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const
    {
        return (m_LArSoftGeometry->TPC(tpc, cstat).DriftDirection() == geo::kPosX ?
                    m_LArSoftGeometry->View(geo::PlaneID(cstat, tpc, 1)) :
                    m_LArSoftGeometry->View(geo::PlaneID(cstat, tpc, 2)));
    }

    inline geo::View_t ICARUS::TargetViewW(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const
    {
        return m_LArSoftGeometry->View(geo::PlaneID(cstat, tpc, 0));
    }

    inline float ICARUS::WireAngleW(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const
    {
        return std::abs(detector_functions::WireAngle(this->TargetViewW(tpc, cstat), tpc, cstat, m_LArSoftGeometry));
    }
}
