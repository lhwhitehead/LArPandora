# LArPandora (last updated on 16th December 2014)

Primary authors: Andy Blake, John Marshall, Mark Thomson (Cambridge University)

This code is part of the Liquid Argon Software (LArSoft) project.
It contains simulation and reconstruction algorithms for LAr TPC detectors.
If you have a problem, please log a redmine issue: https://cdcvs.fnal.gov/redmine/projects/larsoft/issues/new

## Dependencies

```
larpandora
|__larpandoracontent
|__larreco
   |__larsim
   |  |__larg4
   |  |  |__larevt
   |  |  |  |__lardata
   |  |  |  |  |__larcore
   |  |  |  |  |  |__larcorealg
   |  |  |  |  |     |__larcoreobj
   |  |  |  |  |__lardataalg
   |  |  |  |  |  |__lardataobj
   |  |  |  |  |__larvecutils
```

## Overview

The larpandora repository contains the interfaces and algorithms for running the Pandora reconstruction chain within LArSoft. Pandora provides a highly modular approach to event reconstruction in fine-grain detectors, using a series of focused algorithms to reconstruct the particle flow of an event. This Particle Flow approach has now been implemented for LAr-TPC event reconstruction within LArSoft. The Pandora reconstruction currently supports the MicroBooNE and LBNE 35t detector geometries.

The Pandora LAr-TPC reconstruction chain takes as its input 2D hits and builds a set of 3D particles. The reconstruction chain runs within the lightweight framework supplied by the Pandora Software Development Kit (SDK), which manages the algorithms and provides a set of APIs for controlled memory management. The LAr-TPC algorithms themselves are developed and housed within LArSoft, and are run inside LArSoft using an ART Producer module, which inputs recob::Hit objects and outputs recob::PFParticle objects. The aim is to return one reconstructed particle for each true final-state particle in the event. The reconstruction also returns the parent/daughter hierarchy of particle associations (representing the particle flow of the event), along with a series of ART associations to low-level objects (recob::Cluster, recob::Seed, recob::SpacePoint).

The following sections provide notes on the two packages within the larpandora repository, LArPandoraAlgorithms and LArPandoraInterface, which support the pattern recognition algorithms and ART/LArSoft inputs/outputs respectively. Also included are instructions for running the Pandora reconstruction within LArSoft.

## Packages

### LArPandoraAlgorithms

This package houses all the LAr-TPC specific helper functions and pattern recognition algorithms (note that this package only depends on the underlying Pandora SDK and so can exist both inside and outside LArSoft). The package is currently divided into a number of sub-directories, corresponding to different aspects of LAr-TPC reconstruction (e.g. 2D and 3D).

### LArPandoraInterface

This package contains the interface between ART/LArSoft and the Pandora SDK. The central component is an ART Producer module that reads in recob::Hit objects from the ART framework, passes them to the Pandora SDK for pattern recognition, and then writes the reconstructed proto-particles back to the ART framework as recob::PFParticle objects. The LArPandoraInterface package holds a number of additional Producer and Analyzer modules that manipulate and analyse the reconstructed recob::PFParticle objects. Also distributed in this packages are .fcl scripts for configuring and running the Producer modules, and a number of Pandora .xml steering files, which are loaded into Pandora by the Producer module and define the order and configuration of the pattern recognition algorithms.

### Pandora SDK (Note: external package).

This external package houses a lightweight framework for running pattern recognition algorithms and performing memory management operations. The Pandora SDK also supplies design-pattern algorithms and helper functions that are used in building the MicroBooNE and LBNE reconstruction chains. Note that the LAr-TPC specific algorithms and helpers live in the LArPandoraAlgorithms package of LArSoft.

## Instructions

### Running the reconstruction

Taking an example for MicroBooNE, the LArPandoraInterface package in larpandora contains a script "runpandora_microboone.fcl" that can be used to process collections of reconstructed 2D hits. This script inputs these hits and runs the pattern recognition. It is run as follows:

```
lar -c runpandora_microboone.fcl /path/to/file/of/reconstructed/hits.root
```

For completeness, here is the current version of the runpandora_microboone.fcl file in full.

```
#include "services_microboone.fcl"
#include "pandoramodules_microboone.fcl"

process_name: LArPandora

### SERVICES ###
services:
{
  message:      @local::standard_debug
  user:         @local::microboone_services
}

### INPUT ###
source:
{
  module_type: RootInput
}

### MODULES ###
physics:
{
  producers: 
  {  
    pandora:    @local::microboone_pandora 
  }

  reco: [pandora]

  trigger_paths: [reco]
}
```

(Note: this script will be moved to the uboonecode repository in due course)

### Build instructions for Pandora SDK and Monitoring packages

The larpandora repository depends on the Pandora SDK. In addition to the SDK, there is also an optional Pandora Monitoring package, which depends on ROOT. Both packages can be downloaded from the "Pandora SVN repository":https://svnsrv.desy.de/public/PandoraPFANew/ which is hosted at "DESY":https://svnsrv.desy.de. The packages are also installed in the /grid/fermiapp area at Fermilab. Here are a set of instructions for checking put and building the SDK and Monitoring packages:

```
### STEP 0 (SET UP ROOT)
source /grid/fermiapp/products/uboone/setup_uboone.sh
setup root

### STEP 1 (SET UP ENVIRONMENT)
export MY_INSTALLATION=/path/to/my/installation/directory

export PANDORA_VERSION=v00-17
export PANDORA_DIR=${MY_INSTALLATION}/PandoraPFA
export PANDORA_INC=${PANDORA_DIR}/include
export PANDORA_LIB=${PANDORA_DIR}/lib

export PATH=${PANDORA_INC}:${PATH}
export LD_LIBRARY_PATH=${PANDORA_LIB}:${LD_LIBRARY_PATH}

### STEP 2 (CHECK OUT AND BUILD PANDORA)
svn co https://svnsrv.desy.de/public/PandoraPFANew/PandoraPFANew/tags/${PANDORA_VERSION} ${PANDORA_DIR}
svn co https://svnsrv.desy.de/public/PandoraPFANew/PandoraSDK/tags/${PANDORA_VERSION} ${PANDORA_DIR}/PandoraSDK
svn co https://svnsrv.desy.de/public/PandoraPFANew/PandoraMonitoring/tags/${PANDORA_VERSION} ${PANDORA_DIR}/PandoraMonitoring

cd ${PANDORA_DIR}
make MONITORING=1 
make install MONITORING=1 INCLUDE_TARGET=${PANDORA_INC}
```

