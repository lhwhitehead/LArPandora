#include "larpandora/LArPandoraInterface/Detectors/LArPandoraDetectorType.h"

#include "larcore/Geometry/Geometry.h"

namespace lar_pandora{

    class DUNEFarDetVDThreeView : public LArPandoraDetectorType {
    public:
        DUNEFarDetVDThreeView();
        geo::View_t TargetViewU(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const override;
        geo::View_t TargetViewV(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const override;
        geo::View_t TargetViewW(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const override;
        float WirePitchU() const override;
        float WirePitchV() const override;
        float WirePitchW() const override;
        float WireAngleU(const int tpc, const int cstat) const override {return 0.f; };
        float WireAngleV(const int tpc, const int cstat) const override {return 0.f; };
        float WireAngleW(const int tpc, const int cstat) const override {return 0.f; };
        bool ShouldSwitchUV(const unsigned int tpc, const unsigned int cstat) const override {return false; };
        void LoadDetectorGaps(LArDetectorGapList& listOfGaps) override {return; }; 
    private:
        art::ServiceHandle<geo::Geometry> m_LArSoftGeometry;
    };

    inline geo::View_t DUNEFarDetVDThreeView::TargetViewU(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const
    {
        return m_LArSoftGeometry->View(geo::PlaneID(cstat, tpc, 0));
    }

    inline geo::View_t DUNEFarDetVDThreeView::TargetViewV(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const
    {
        return m_LArSoftGeometry->View(geo::PlaneID(cstat, tpc, 1));
    }

    inline geo::View_t DUNEFarDetVDThreeView::TargetViewW(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const
    {
        return m_LArSoftGeometry->View(geo::PlaneID(cstat, tpc, 2));
    }

    inline float DUNEFarDetVDThreeView::WirePitchU() const
    {
        return m_LArSoftGeometry->WirePitch(this->TargetViewU(0,0));
    }

    inline float DUNEFarDetVDThreeView::WirePitchV() const
    {
        return m_LArSoftGeometry->WirePitch(this->TargetViewV(0,0));
    }

    inline float DUNEFarDetVDThreeView::WirePitchW() const
    {
        return m_LArSoftGeometry->WirePitch(this->TargetViewW(0,0));
    }

}
