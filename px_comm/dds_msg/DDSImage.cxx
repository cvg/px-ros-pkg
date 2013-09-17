
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDSImage.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/


#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
        #ifndef dds_c_log_impl_h              
            #include "dds_c/dds_c_log_impl.h"                                
        #endif        
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
    
    #ifndef cdr_type_h
        #include "cdr/cdr_type.h"
    #endif    

    #ifndef osapi_heap_h
        #include "osapi/osapi_heap.h" 
    #endif
#else
    #include "ndds_standalone_type.h"
#endif



#include "DDSImage.h"


namespace px_comm{
/* ========================================================================= */
const char *DDSImageTYPENAME = "px_comm::DDSImage";

DDS_TypeCode* DDSImage_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode DDSImage_g_tc_frame_id_string = DDS_INITIALIZE_STRING_TYPECODE(255);
    static DDS_TypeCode DDSImage_g_tc_encoding_string = DDS_INITIALIZE_STRING_TYPECODE(255);
    static DDS_TypeCode DDSImage_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(1251936,NULL);

    static DDS_TypeCode_Member DDSImage_g_tc_members[10]=
    {
        {
            (char *)"seq",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"stamp_sec",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"stamp_nsec",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"frame_id",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"height",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"width",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"encoding",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"is_bigendian",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"step",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"data",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DDSImage_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"px_comm::DDSImage", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        10, /* Number of members */
        DDSImage_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DDSImage*/

    if (is_initialized) {
        return &DDSImage_g_tc;
    }

    DDSImage_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    DDSImage_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    DDSImage_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DDSImage_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DDSImage_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDSImage_g_tc_frame_id_string;
    DDSImage_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    DDSImage_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    DDSImage_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDSImage_g_tc_encoding_string;
    DDSImage_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DDSImage_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    DDSImage_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDSImage_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &DDSImage_g_tc;
}


RTIBool DDSImage_initialize(
    DDSImage* sample) {
  return ::px_comm::DDSImage_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool DDSImage_initialize_ex(
    DDSImage* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initUnsignedLong(&sample->seq)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initLong(&sample->stamp_sec)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initLong(&sample->stamp_nsec)) {
        return RTI_FALSE;
    }                
            

    if (allocateMemory) {
        sample->frame_id = DDS_String_alloc((255));
        if (sample->frame_id == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->frame_id != NULL) { 
            sample->frame_id[0] = '\0';
        }
    }
            

    if (!RTICdrType_initUnsignedLong(&sample->height)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initUnsignedLong(&sample->width)) {
        return RTI_FALSE;
    }                
            

    if (allocateMemory) {
        sample->encoding = DDS_String_alloc((255));
        if (sample->encoding == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->encoding != NULL) { 
            sample->encoding[0] = '\0';
        }
    }
            

    if (!RTICdrType_initChar(&sample->is_bigendian)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initUnsignedLong(&sample->step)) {
        return RTI_FALSE;
    }                
            

    if (allocateMemory) {
        DDS_CharSeq_initialize(&sample->data);
        if (!DDS_CharSeq_set_maximum(&sample->data,
                (1251936))) {
            return RTI_FALSE;
        }
    } else {
        DDS_CharSeq_set_length(&sample->data, 0); 
    }
            


    return RTI_TRUE;
}

void DDSImage_finalize(
    DDSImage* sample)
{
    ::px_comm::DDSImage_finalize_ex(sample,RTI_TRUE);
}
        
void DDSImage_finalize_ex(
    DDSImage* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */





    DDS_String_free(sample->frame_id);                
            



    DDS_String_free(sample->encoding);                
            



    DDS_CharSeq_finalize(&sample->data);
            

}

RTIBool DDSImage_copy(
    DDSImage* dst,
    const DDSImage* src)
{        

    if (!RTICdrType_copyUnsignedLong(
        &dst->seq, &src->seq)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyLong(
        &dst->stamp_sec, &src->stamp_sec)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyLong(
        &dst->stamp_nsec, &src->stamp_nsec)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyString(
        dst->frame_id, src->frame_id, (255) + 1)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyUnsignedLong(
        &dst->height, &src->height)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyUnsignedLong(
        &dst->width, &src->width)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyString(
        dst->encoding, src->encoding, (255) + 1)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyChar(
        &dst->is_bigendian, &src->is_bigendian)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyUnsignedLong(
        &dst->step, &src->step)) {
        return RTI_FALSE;
    }
            

    if (!DDS_CharSeq_copy_no_alloc(&dst->data,
                                          &src->data)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DDSImage' sequence class.
 */
#define T DDSImage
#define TSeq DDSImageSeq
#define T_initialize_ex ::px_comm::DDSImage_initialize_ex
#define T_finalize_ex   ::px_comm::DDSImage_finalize_ex
#define T_copy       ::px_comm::DDSImage_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T


} /* namespace px_comm */
