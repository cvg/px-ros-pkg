
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDSImage.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef DDSImageSupport_248003145_h
#define DDSImageSupport_248003145_h

/* Uses */
#include "DDSImage.h"

#ifdef __cplusplus
#ifndef ndds_cpp_h
  #include "ndds/ndds_cpp.h"
#endif
#else
#ifndef ndds_c_h
  #include "ndds/ndds_c.h"
#endif
#endif

        
namespace px_comm {
    /* ========================================================================= */
    /**
       Uses:     T

       Defines:  TTypeSupport, TDataWriter, TDataReader

       Organized using the well-documented "Generics Pattern" for
       implementing generics in C and C++.
    */

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
      /* If the code is building on Windows, start exporting symbols.
       */
    #undef NDDSUSERDllExport
      #define NDDSUSERDllExport __declspec(dllexport)

    #endif

    #ifdef __cplusplus

    DDS_TYPESUPPORT_CPP(DDSImageTypeSupport, DDSImage);

    DDS_DATAWRITER_CPP(DDSImageDataWriter, DDSImage);
    DDS_DATAREADER_CPP(DDSImageDataReader, DDSImageSeq, DDSImage);

    #else

    DDS_TYPESUPPORT_C(DDSImageTypeSupport, DDSImage);
    DDS_DATAWRITER_C(DDSImageDataWriter, DDSImage);
    DDS_DATAREADER_C(DDSImageDataReader, DDSImageSeq, DDSImage);

    #endif

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
      /* If the code is building on Windows, stop exporting symbols.
       */
    #undef NDDSUSERDllExport
      #define NDDSUSERDllExport
    #endif
} /* namespace px_comm  */

#endif  /* DDSImageSupport_248003145_h */

