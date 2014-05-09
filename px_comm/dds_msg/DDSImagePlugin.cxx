

/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDSImage.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#include <string.h>

#ifdef __cplusplus
#ifndef ndds_cpp_h
  #include "ndds/ndds_cpp.h"
#endif
#else
#ifndef ndds_c_h
  #include "ndds/ndds_c.h"
#endif
#endif

#ifndef osapi_type_h
  #include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
  #include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
  #include "osapi/osapi_utility.h"
#endif

#ifndef cdr_type_h
  #include "cdr/cdr_type.h"
#endif

#ifndef cdr_type_object_h
  #include "cdr/cdr_typeObject.h"
#endif

#ifndef cdr_encapsulation_h
  #include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
  #include "cdr/cdr_stream.h"
#endif

#ifndef pres_typePlugin_h
  #include "pres/pres_typePlugin.h"
#endif

#include "DDSImagePlugin.h"

namespace px_comm {

    /* ----------------------------------------------------------------------------
     *  Type DDSImage
     * -------------------------------------------------------------------------- */

    /* -----------------------------------------------------------------------------
        Support functions:
    * -------------------------------------------------------------------------- */

    DDSImage*
    DDSImagePluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params){
        DDSImage *sample = NULL;

        RTIOsapiHeap_allocateStructure(
                &sample, DDSImage);

        if(sample != NULL) {
            if (!px_comm::DDSImage_initialize_w_params(sample,alloc_params)) {
                RTIOsapiHeap_freeStructure(sample);
                return NULL;
            }
        }        
        return sample; 
    } 

    DDSImage *
    DDSImagePluginSupport_create_data_ex(RTIBool allocate_pointers){
        DDSImage *sample = NULL;

        RTIOsapiHeap_allocateStructure(
                &sample, DDSImage);

        if(sample != NULL) {
            if (!px_comm::DDSImage_initialize_ex(sample,allocate_pointers, RTI_TRUE)) {
                RTIOsapiHeap_freeStructure(sample);
                return NULL;
            }
        }
        return sample; 
    }

    DDSImage *
    DDSImagePluginSupport_create_data(void)
    {
        return px_comm::DDSImagePluginSupport_create_data_ex(RTI_TRUE);
    }

    void 
    DDSImagePluginSupport_destroy_data_w_params(
        DDSImage *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params) {

        px_comm::DDSImage_finalize_w_params(sample,dealloc_params);

        RTIOsapiHeap_freeStructure(sample);
    }

    void 
    DDSImagePluginSupport_destroy_data_ex(
        DDSImage *sample,RTIBool deallocate_pointers) {

        px_comm::DDSImage_finalize_ex(sample,deallocate_pointers);

        RTIOsapiHeap_freeStructure(sample);
    }

    void 
    DDSImagePluginSupport_destroy_data(
        DDSImage *sample) {

        px_comm::DDSImagePluginSupport_destroy_data_ex(sample,RTI_TRUE);

    }

    RTIBool 
    DDSImagePluginSupport_copy_data(
        DDSImage *dst,
        const DDSImage *src)
    {
        return px_comm::DDSImage_copy(dst,src);
    }

    void 
    DDSImagePluginSupport_print_data(
        const DDSImage *sample,
        const char *desc,
        unsigned int indent_level)
    {

        RTICdrType_printIndent(indent_level);

        if (desc != NULL) {
            RTILog_debug("%s:\n", desc);
        } else {
            RTILog_debug("\n");
        }

        if (sample == NULL) {
            RTILog_debug("NULL\n");
            return;
        }

        RTICdrType_printUnsignedLong(
                &sample->seq, "seq", indent_level + 1);    

        RTICdrType_printLong(
                &sample->stamp_sec, "stamp_sec", indent_level + 1);    

        RTICdrType_printLong(
                &sample->stamp_nsec, "stamp_nsec", indent_level + 1);    

        if (sample->frame_id==NULL) {
            RTICdrType_printString(
                NULL,"frame_id", indent_level + 1);
        } else {
            RTICdrType_printString(
                sample->frame_id,"frame_id", indent_level + 1);    
        }

        RTICdrType_printUnsignedLong(
                &sample->height, "height", indent_level + 1);    

        RTICdrType_printUnsignedLong(
                &sample->width, "width", indent_level + 1);    

        if (sample->encoding==NULL) {
            RTICdrType_printString(
                NULL,"encoding", indent_level + 1);
        } else {
            RTICdrType_printString(
                sample->encoding,"encoding", indent_level + 1);    
        }

        RTICdrType_printChar(
                &sample->is_bigendian, "is_bigendian", indent_level + 1);    

        RTICdrType_printUnsignedLong(
                &sample->step, "step", indent_level + 1);    

        if (&sample->data == NULL) {
            RTICdrType_printIndent(indent_level+ 1);
            RTILog_debug("data: NULL\n");
        } else {

            if (DDS_CharSeq_get_contiguous_bufferI(&sample->data) != NULL) {
                RTICdrType_printArray(
                            DDS_CharSeq_get_contiguous_bufferI(&sample->data),
                            DDS_CharSeq_get_length(&sample->data),
                            RTI_CDR_CHAR_SIZE,
                            (RTICdrTypePrintFunction)RTICdrType_printChar,
                             "data", indent_level + 1);
            } else {
                RTICdrType_printPointerArray(
                                DDS_CharSeq_get_discontiguous_bufferI(&sample->data),
                                DDS_CharSeq_get_length(&sample->data ),
                                (RTICdrTypePrintFunction)RTICdrType_printChar,
                                 "data", indent_level + 1);
            }

        }

    }

    /* ----------------------------------------------------------------------------
        Callback functions:
    * ---------------------------------------------------------------------------- */

    PRESTypePluginParticipantData 
    DDSImagePlugin_on_participant_attached(
        void *registration_data,
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration,
        void *container_plugin_context,
        RTICdrTypeCode *type_code)
    {
        if (registration_data) {} /* To avoid warnings */
        if (participant_info) {} /* To avoid warnings */
        if (top_level_registration) {} /* To avoid warnings */
        if (container_plugin_context) {} /* To avoid warnings */
        if (type_code) {} /* To avoid warnings */

        return PRESTypePluginDefaultParticipantData_new(participant_info);

    }

    void 
    DDSImagePlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data)
    {

        PRESTypePluginDefaultParticipantData_delete(participant_data);
    }

    PRESTypePluginEndpointData
    DDSImagePlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *containerPluginContext)
    {
        PRESTypePluginEndpointData epd = NULL;

        unsigned int serializedSampleMaxSize;

        if (top_level_registration) {} /* To avoid warnings */
        if (containerPluginContext) {} /* To avoid warnings */

        epd = PRESTypePluginDefaultEndpointData_new(
                    participant_data,
                    endpoint_info,
                    (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
                    px_comm::DDSImagePluginSupport_create_data,
                    (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
                    px_comm::DDSImagePluginSupport_destroy_data,
                     NULL , NULL );

        if (epd == NULL) {
            return NULL;
        } 

        if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
            serializedSampleMaxSize = px_comm::DDSImagePlugin_get_serialized_sample_max_size(
                        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

            PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

            if (PRESTypePluginDefaultEndpointData_createWriterPool(
                            epd,
                            endpoint_info,
                        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                            px_comm::DDSImagePlugin_get_serialized_sample_max_size, epd,
                        (PRESTypePluginGetSerializedSampleSizeFunction)
                        px_comm::DDSImagePlugin_get_serialized_sample_size,
                        epd) == RTI_FALSE) {
                PRESTypePluginDefaultEndpointData_delete(epd);
                return NULL;
            }
        }

        return epd;    
    }

    void 
    DDSImagePlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data)
    {  

        PRESTypePluginDefaultEndpointData_delete(endpoint_data);
    }

    void    
    DDSImagePlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        DDSImage *sample,
        void *handle)
    {

        DDSImage_finalize_optional_members(sample, RTI_TRUE);

        PRESTypePluginDefaultEndpointData_returnSample(
                endpoint_data, sample, handle);
    }

    RTIBool 
    DDSImagePlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        DDSImage *dst,
        const DDSImage *src)
    {
        if (endpoint_data) {} /* To avoid warnings */
        return px_comm::DDSImagePluginSupport_copy_data(dst,src);
    }

    /* ----------------------------------------------------------------------------
        (De)Serialize functions:
    * ------------------------------------------------------------------------- */
    unsigned int 
    DDSImagePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    RTIBool 
    DDSImagePlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const DDSImage *sample, 
        struct RTICdrStream *stream,    
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos)
    {
        char * position = NULL;
        RTIBool retval = RTI_TRUE;

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(serialize_encapsulation) {
            if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }

        if(serialize_sample) {

            if (!RTICdrStream_serializeUnsignedLong(
                stream, &sample->seq)) {
                return RTI_FALSE;
            }

            if (!RTICdrStream_serializeLong(
                stream, &sample->stamp_sec)) {
                return RTI_FALSE;
            }

            if (!RTICdrStream_serializeLong(
                stream, &sample->stamp_nsec)) {
                return RTI_FALSE;
            }

            if (!RTICdrStream_serializeString(
                stream, sample->frame_id, (255) + 1)) {
                return RTI_FALSE;
            }

            if (!RTICdrStream_serializeUnsignedLong(
                stream, &sample->height)) {
                return RTI_FALSE;
            }

            if (!RTICdrStream_serializeUnsignedLong(
                stream, &sample->width)) {
                return RTI_FALSE;
            }

            if (!RTICdrStream_serializeString(
                stream, sample->encoding, (255) + 1)) {
                return RTI_FALSE;
            }

            if (!RTICdrStream_serializeChar(
                stream, &sample->is_bigendian)) {
                return RTI_FALSE;
            }

            if (!RTICdrStream_serializeUnsignedLong(
                stream, &sample->step)) {
                return RTI_FALSE;
            }

            if (DDS_CharSeq_get_contiguous_bufferI(&sample->data) != NULL) {
                if (!RTICdrStream_serializePrimitiveSequence(
                             stream,
                             DDS_CharSeq_get_contiguous_bufferI(&sample->data),
                             DDS_CharSeq_get_length(&sample->data),
                             (1251936),
                             RTI_CDR_CHAR_TYPE)) {
                    return RTI_FALSE;
                } 
            } else {
                if (!RTICdrStream_serializePrimitivePointerSequence(
                             stream,
                             (const void **) DDS_CharSeq_get_discontiguous_bufferI(&sample->data),
                             DDS_CharSeq_get_length(&sample->data),
                             (1251936), 
                             RTI_CDR_CHAR_TYPE)) {
                    return RTI_FALSE;
                } 
            } 

        }

        if(serialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return retval;
    }

    RTIBool 
    DDSImagePlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        DDSImage *sample,
        struct RTICdrStream *stream,   
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos)
    {

        char * position = NULL;

        RTIBool done = RTI_FALSE;

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */
        if(deserialize_encapsulation) {

            if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }
        if(deserialize_sample) {

            px_comm::DDSImage_initialize_ex(sample, RTI_FALSE, RTI_FALSE);

            if (!RTICdrStream_deserializeUnsignedLong(
                stream, &sample->seq)) {
                goto fin; 
            }
            if (!RTICdrStream_deserializeLong(
                stream, &sample->stamp_sec)) {
                goto fin; 
            }
            if (!RTICdrStream_deserializeLong(
                stream, &sample->stamp_nsec)) {
                goto fin; 
            }
            if (!RTICdrStream_deserializeString(
                stream, sample->frame_id, (255) + 1)) {
                goto fin; 
            }
            if (!RTICdrStream_deserializeUnsignedLong(
                stream, &sample->height)) {
                goto fin; 
            }
            if (!RTICdrStream_deserializeUnsignedLong(
                stream, &sample->width)) {
                goto fin; 
            }
            if (!RTICdrStream_deserializeString(
                stream, sample->encoding, (255) + 1)) {
                goto fin; 
            }
            if (!RTICdrStream_deserializeChar(
                stream, &sample->is_bigendian)) {
                goto fin; 
            }
            if (!RTICdrStream_deserializeUnsignedLong(
                stream, &sample->step)) {
                goto fin; 
            }
            {
                RTICdrUnsignedLong sequence_length;
                if (DDS_CharSeq_get_contiguous_bufferI(&sample->data) != NULL) {
                    if (!RTICdrStream_deserializePrimitiveSequence(
                            stream,
                            DDS_CharSeq_get_contiguous_bufferI(&sample->data),
                            &sequence_length,
                            DDS_CharSeq_get_maximum(&sample->data),
                            RTI_CDR_CHAR_TYPE)) {
                        goto fin; 
                    }
                } else {
                    if (!RTICdrStream_deserializePrimitivePointerSequence(
                            stream,
                            (void **) DDS_CharSeq_get_discontiguous_bufferI(&sample->data),
                            &sequence_length,
                            DDS_CharSeq_get_maximum(&sample->data),
                            RTI_CDR_CHAR_TYPE)) {
                        goto fin; 
                    }
                }
                if (!DDS_CharSeq_set_length(&sample->data, sequence_length)) {
                    return RTI_FALSE;
                }

            }
        }

        done = RTI_TRUE;
        fin:
        if (done != RTI_TRUE && 
                RTICdrStream_getRemainder(stream) >=
                   RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
        if(deserialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;
    }

    RTIBool 
    DDSImagePlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        DDSImage **sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,   
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos)
    {

        RTIBool result;
        if (drop_sample) {} /* To avoid warnings */

        stream->_xTypesState.unassignable = RTI_FALSE;
        result= px_comm::DDSImagePlugin_deserialize_sample( 
                endpoint_data, (sample != NULL)?*sample:NULL,
                stream, deserialize_encapsulation, deserialize_sample, 
                endpoint_plugin_qos);
        if (result) {
            if (stream->_xTypesState.unassignable) {
                result = RTI_FALSE;
            }
        }

        return result;

    }

    RTIBool DDSImagePlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream,   
        RTIBool skip_encapsulation,
        RTIBool skip_sample, 
        void *endpoint_plugin_qos)
    {
        char * position = NULL;

        RTIBool done = RTI_FALSE;

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(skip_encapsulation) {
            if (!RTICdrStream_skipEncapsulation(stream)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }

        if (skip_sample) {

            if (!RTICdrStream_skipUnsignedLong (stream)) {
                goto fin; 
            }
            if (!RTICdrStream_skipLong (stream)) {
                goto fin; 
            }
            if (!RTICdrStream_skipLong (stream)) {
                goto fin; 
            }
            if (!RTICdrStream_skipString (stream, (255)+1)) {
                goto fin; 
            }
            if (!RTICdrStream_skipUnsignedLong (stream)) {
                goto fin; 
            }
            if (!RTICdrStream_skipUnsignedLong (stream)) {
                goto fin; 
            }
            if (!RTICdrStream_skipString (stream, (255)+1)) {
                goto fin; 
            }
            if (!RTICdrStream_skipChar (stream)) {
                goto fin; 
            }
            if (!RTICdrStream_skipUnsignedLong (stream)) {
                goto fin; 
            }
            {
                RTICdrUnsignedLong sequence_length;
                if (!RTICdrStream_skipPrimitiveSequence(
                    stream,
                    &sequence_length,
                        RTI_CDR_CHAR_TYPE)){
                    goto fin; 
                }
            }
        }

        done = RTI_TRUE;
        fin:
        if (done != RTI_TRUE && 
                RTICdrStream_getRemainder(stream) >=
                   RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
        if(skip_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;
    }

    unsigned int 
    DDSImagePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {

        unsigned int initial_alignment = current_alignment;

        unsigned int encapsulation_size = current_alignment;

        if (endpoint_data) {} /* To avoid warnings */ 

        if (include_encapsulation) {

            if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
                return 1;
            }
            RTICdrStream_getEncapsulationSize(encapsulation_size);
            encapsulation_size -= current_alignment;
            current_alignment = 0;
            initial_alignment = 0;
        }

        current_alignment +=RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);

        current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);

        current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);

        current_alignment +=RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (255)+1);

        current_alignment +=RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);

        current_alignment +=RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);

        current_alignment +=RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (255)+1);

        current_alignment +=RTICdrType_getCharMaxSizeSerialized(
        current_alignment);

        current_alignment +=RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);

        current_alignment +=RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
            current_alignment,(1251936),RTI_CDR_CHAR_TYPE) ;

        if (include_encapsulation) {
            current_alignment += encapsulation_size;
        }
        return  current_alignment - initial_alignment;
    }

    unsigned int 
    DDSImagePlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {

        unsigned int initial_alignment = current_alignment;

        unsigned int encapsulation_size = current_alignment;

        if (endpoint_data) {} /* To avoid warnings */ 

        if (include_encapsulation) {

            if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
                return 1;
            }
            RTICdrStream_getEncapsulationSize(encapsulation_size);
            encapsulation_size -= current_alignment;
            current_alignment = 0;
            initial_alignment = 0;
        }

        current_alignment +=RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
        current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
        current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
        current_alignment +=RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
        current_alignment +=RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
        current_alignment +=RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
        current_alignment +=RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
        current_alignment +=RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
        current_alignment +=RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
        current_alignment +=    RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
            current_alignment,0, RTI_CDR_CHAR_TYPE);

        if (include_encapsulation) {
            current_alignment += encapsulation_size;
        }
        return  current_alignment - initial_alignment;
    }

    /* Returns the size of the sample in its serialized form (in bytes).
     * It can also be an estimation in excess of the real buffer needed 
     * during a call to the serialize() function.
     * The value reported does not have to include the space for the
     * encapsulation flags.
     */
    unsigned int
    DDSImagePlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const DDSImage * sample) 
    {

        unsigned int initial_alignment = current_alignment;

        unsigned int encapsulation_size = current_alignment;

        if (endpoint_data) {} /* To avoid warnings */ 
        if (sample) {} /* To avoid warnings */

        if (include_encapsulation) {

            if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
                return 1;
            }
            RTICdrStream_getEncapsulationSize(encapsulation_size);
            encapsulation_size -= current_alignment;
            current_alignment = 0;
            initial_alignment = 0;
        }

        current_alignment += RTICdrType_getUnsignedLongMaxSizeSerialized(
                                  current_alignment);
        current_alignment += RTICdrType_getLongMaxSizeSerialized(
                                  current_alignment);
        current_alignment += RTICdrType_getLongMaxSizeSerialized(
                                  current_alignment);
        current_alignment += RTICdrType_getStringSerializedSize(
                                  current_alignment, sample->frame_id);
        current_alignment += RTICdrType_getUnsignedLongMaxSizeSerialized(
                                  current_alignment);
        current_alignment += RTICdrType_getUnsignedLongMaxSizeSerialized(
                                  current_alignment);
        current_alignment += RTICdrType_getStringSerializedSize(
                                  current_alignment, sample->encoding);
        current_alignment += RTICdrType_getCharMaxSizeSerialized(
                                  current_alignment);
        current_alignment += RTICdrType_getUnsignedLongMaxSizeSerialized(
                                  current_alignment);
        current_alignment += RTICdrType_getPrimitiveSequenceSerializedSize(
            current_alignment, 
            DDS_CharSeq_get_length(&sample->data),
            RTI_CDR_CHAR_TYPE);

        if (include_encapsulation) {
            current_alignment += encapsulation_size;
        }
        return current_alignment - initial_alignment;
    }

    /* --------------------------------------------------------------------------------------
        Key Management functions:
    * -------------------------------------------------------------------------------------- */

    PRESTypePluginKeyKind 
    DDSImagePlugin_get_key_kind(void)
    {
        return PRES_TYPEPLUGIN_NO_KEY;
    }

    RTIBool 
    DDSImagePlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const DDSImage *sample, 
        struct RTICdrStream *stream,    
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos)
    {
        char * position = NULL;
        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(serialize_encapsulation) {
            if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }

        if(serialize_key) {

            if (!px_comm::DDSImagePlugin_serialize(
                     endpoint_data,
                     sample,
                     stream,
                     RTI_FALSE, encapsulation_id,
                     RTI_TRUE,
                     endpoint_plugin_qos)) {
                return RTI_FALSE;
            }

        }

        if(serialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;
    }

    RTIBool DDSImagePlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        DDSImage *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos)
    {
        char * position = NULL;

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(deserialize_encapsulation) {

            if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }
        if (deserialize_key) {

            if (!px_comm::DDSImagePlugin_deserialize_sample(
                     endpoint_data, sample, stream, 
                     RTI_FALSE, RTI_TRUE, 
                     endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }

        if(deserialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;
    }

    RTIBool DDSImagePlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        DDSImage **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos)
    {
        RTIBool result;
        if (drop_sample) {} /* To avoid warnings */
        stream->_xTypesState.unassignable = RTI_FALSE;
        result= px_comm::DDSImagePlugin_deserialize_key_sample(
                endpoint_data, (sample != NULL)?*sample:NULL, stream,
                deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
        if (result) {
            if (stream->_xTypesState.unassignable) {
                result = RTI_FALSE;
            }
        }

        return result;    

    }

    unsigned int
    DDSImagePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {

        unsigned int initial_alignment = current_alignment;

        unsigned int encapsulation_size = current_alignment;

        if (endpoint_data) {} /* To avoid warnings */

        if (include_encapsulation) {

            if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
                return 1;
            }
            RTICdrStream_getEncapsulationSize(encapsulation_size);
            encapsulation_size -= current_alignment;
            current_alignment = 0;
            initial_alignment = 0;
        }

        current_alignment += px_comm::DDSImagePlugin_get_serialized_sample_max_size(
                                   endpoint_data,RTI_FALSE, encapsulation_id, current_alignment);

        if (include_encapsulation) {
            current_alignment += encapsulation_size;
        }
        return current_alignment - initial_alignment;
    }

    RTIBool 
    DDSImagePlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        DDSImage *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos)
    {
        char * position = NULL;

        RTIBool done = RTI_FALSE;

        if (stream == NULL) goto fin; /* To avoid warnings */
        if(deserialize_encapsulation) {
            if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
                return RTI_FALSE;
            }
            position = RTICdrStream_resetAlignment(stream);
        }

        if (deserialize_key) {

            if (!px_comm::DDSImagePlugin_deserialize_sample(
                     endpoint_data, sample, stream, RTI_FALSE, 
                     RTI_TRUE, endpoint_plugin_qos)) {
                return RTI_FALSE;
            }

        }

        done = RTI_TRUE;
        fin:
        if (done != RTI_TRUE && 
                RTICdrStream_getRemainder(stream) >=
                   RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }

        if(deserialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;
    }

    /* ------------------------------------------------------------------------
     * Plug-in Installation Methods
     * ------------------------------------------------------------------------ */
    struct PRESTypePlugin *DDSImagePlugin_new(void) 
    { 
        struct PRESTypePlugin *plugin = NULL;
        const struct PRESTypePluginVersion PLUGIN_VERSION = 
                PRES_TYPE_PLUGIN_VERSION_2_0;

        RTIOsapiHeap_allocateStructure(
                &plugin, struct PRESTypePlugin);
        if (plugin == NULL) {
            return NULL;
        }

        plugin->version = PLUGIN_VERSION;

        /* set up parent's function pointers */
        plugin->onParticipantAttached =
                (PRESTypePluginOnParticipantAttachedCallback)
                px_comm::DDSImagePlugin_on_participant_attached;
        plugin->onParticipantDetached =
                (PRESTypePluginOnParticipantDetachedCallback)
                px_comm::DDSImagePlugin_on_participant_detached;
        plugin->onEndpointAttached =
                (PRESTypePluginOnEndpointAttachedCallback)
                px_comm::DDSImagePlugin_on_endpoint_attached;
        plugin->onEndpointDetached =
                (PRESTypePluginOnEndpointDetachedCallback)
                px_comm::DDSImagePlugin_on_endpoint_detached;

        plugin->copySampleFnc =
                (PRESTypePluginCopySampleFunction)
                px_comm::DDSImagePlugin_copy_sample;
        plugin->createSampleFnc =
                (PRESTypePluginCreateSampleFunction)
                DDSImagePlugin_create_sample;
        plugin->destroySampleFnc =
                (PRESTypePluginDestroySampleFunction)
                DDSImagePlugin_destroy_sample;

        plugin->serializeFnc =
                (PRESTypePluginSerializeFunction)
                px_comm::DDSImagePlugin_serialize;
        plugin->deserializeFnc =
                (PRESTypePluginDeserializeFunction)
                px_comm::DDSImagePlugin_deserialize;
        plugin->getSerializedSampleMaxSizeFnc =
                (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                px_comm::DDSImagePlugin_get_serialized_sample_max_size;
        plugin->getSerializedSampleMinSizeFnc =
                (PRESTypePluginGetSerializedSampleMinSizeFunction)
                px_comm::DDSImagePlugin_get_serialized_sample_min_size;

        plugin->getSampleFnc =
                (PRESTypePluginGetSampleFunction)
                DDSImagePlugin_get_sample;
        plugin->returnSampleFnc =
                (PRESTypePluginReturnSampleFunction)
                DDSImagePlugin_return_sample;

        plugin->getKeyKindFnc =
                (PRESTypePluginGetKeyKindFunction)
                px_comm::DDSImagePlugin_get_key_kind;

        /* These functions are only used for keyed types. As this is not a keyed
            type they are all set to NULL
            */
        plugin->serializeKeyFnc = NULL ;    
        plugin->deserializeKeyFnc = NULL;  
        plugin->getKeyFnc = NULL;
        plugin->returnKeyFnc = NULL;
        plugin->instanceToKeyFnc = NULL;
        plugin->keyToInstanceFnc = NULL;
        plugin->getSerializedKeyMaxSizeFnc = NULL;
        plugin->instanceToKeyHashFnc = NULL;
        plugin->serializedSampleToKeyHashFnc = NULL;
        plugin->serializedKeyToKeyHashFnc = NULL;    
        plugin->typeCode =  (struct RTICdrTypeCode *)px_comm::DDSImage_get_typecode();
        plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

        /* Serialized buffer */
        plugin->getBuffer = 
                (PRESTypePluginGetBufferFunction)
                DDSImagePlugin_get_buffer;
        plugin->returnBuffer = 
                (PRESTypePluginReturnBufferFunction)
                DDSImagePlugin_return_buffer;
        plugin->getSerializedSampleSizeFnc =
                (PRESTypePluginGetSerializedSampleSizeFunction)
                px_comm::DDSImagePlugin_get_serialized_sample_size;

        plugin->endpointTypeName = DDSImageTYPENAME;

        return plugin;
    }

    void
    DDSImagePlugin_delete(struct PRESTypePlugin *plugin)
    {
        RTIOsapiHeap_freeStructure(plugin);
    } 
} /* namespace px_comm  */

