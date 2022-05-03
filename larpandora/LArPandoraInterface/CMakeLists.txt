include_directories( $ENV{PANDORA_INC} ) ### MIGRATE-ACTION-RECOMMENDED (migrate-3.13.00) - avoid directory-scope functions: use target_link_libraries() with target semantics or target_include_directories() whenever possible
include_directories( $ENV{LARPANDORACONTENT_INC} ) ### MIGRATE-ACTION-RECOMMENDED (migrate-3.13.00) - avoid directory-scope functions: use target_link_libraries() with target semantics or target_include_directories() whenever possible

set(CORE_LIB_LIST
    larpandora_LArPandoraInterface_Detectors
    larcorealg_Geometry
    larcore_Geometry_Geometry_service
    larsim_Simulation lardataobj_Simulation
    larsim_MCCheater_ParticleInventoryService_service
    lardataalg_DetectorInfo
    lardataobj_RawData
    lardataobj_RecoBase
    lardataobj_AnalysisBase
    lardata_ArtDataHelper
    lardata_Utilities
    larreco_RecoAlg_ClusterRecoUtil
    larreco_RecoAlg
    larreco_ClusterFinder
    larreco_Calorimetry
    PANDORASDK
    PANDORAMONITORING
    LArPandoraContent
    nusimdata::SimulationBase
    art::Framework_Core
    art::Framework_Principal
    art::Framework_Services_Registry
    art_root_io::tfile_support
    ROOT::Core
    art_root_io::TFileService_service
    art::Persistency_Common
    art::Persistency_Provenance
    art::Utilities
    canvas::canvas
    messagefacility::MF_MessageLogger
    fhiclcpp::fhiclcpp
    cetlib::cetlib cetlib_except
    ROOT::Geom)

option(PANDORA_LIBTORCH "Flag for building with Pandora's LibTorch-aware algorithms" ON)
if( ${PANDORA_LIBTORCH} AND DEFINED ENV{LIBTORCH_DIR})
    message(STATUS "Building with deep learning support")
    add_definitions("-DLIBTORCH_DL") ### MIGRATE-ACTION-RECOMMENDED (migrate-3.13.00) - avoid directory-scope functions: use target_compile_definitions() or target_compile_features() whenever possible
    art_make(
        LIB_LIBRARIES ${CORE_LIB_LIST} larpandoracontent::LArPandoraDLContent
        MODULE_LIBRARIES larpandora_LArPandoraInterface) ### MIGRATE-ACTION-RECOMMENDED (migrate-3.13.00) - deprecated: use art_make_library(), art_dictonary(), and cet_build_plugin() with explicit source lists and plugin base types
else()
    message( STATUS "Building without deep learning support" )
    art_make(
        LIB_LIBRARIES ${CORE_LIB_LIST}
        MODULE_LIBRARIES larpandora_LArPandoraInterface) ### MIGRATE-ACTION-RECOMMENDED (migrate-3.13.00) - deprecated: use art_make_library(), art_dictonary(), and cet_build_plugin() with explicit source lists and plugin base types
endif()

install_headers()
install_fhicl()
install_source()

add_subdirectory(Detectors)
add_subdirectory(scripts)

