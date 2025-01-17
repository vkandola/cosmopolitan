/* clang-format off */
/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
#include "third_party/mbedtls/test/test.inc"
/*
 * *** THIS FILE WAS MACHINE GENERATED ***
 *
 * This file has been machine generated using the script:
 * generate_test_code.py and then mbedtls_test_suite.sh and then mbedtls_test_suite.sh
 *
 * Test file      : ./test_suite_pkcs5.c
 *
 * The following files were used to create this file.
 *
 *      Main code file      : suites/main_test.function
 *      Platform code file  : suites/host_test.function
 *      Helper file         : suites/helpers.function
 *      Test suite file     : suites/test_suite_pkcs5.function
 *      Test suite data     : suites/test_suite_pkcs5.data
 *
 */


#define TEST_SUITE_ACTIVE

#if defined(MBEDTLS_PKCS5_C)
#include "third_party/mbedtls/pkcs5.h"
void test_pbkdf2_hmac( int hash, data_t * pw_str, data_t * salt_str,
                  int it_cnt, int key_len, data_t * result_key_string )
{
    mbedtls_md_context_t ctx;
    const mbedtls_md_info_t *info;

    unsigned char key[100];

    mbedtls_md_init( &ctx );

    info = mbedtls_md_info_from_type( hash );
    TEST_ASSERT( info != NULL );
    TEST_ASSERT( mbedtls_md_setup( &ctx, info, 1 ) == 0 );
    TEST_ASSERT( mbedtls_pkcs5_pbkdf2_hmac( &ctx, pw_str->x, pw_str->len, salt_str->x, salt_str->len,
                                     it_cnt, key_len, key ) == 0 );

    TEST_ASSERT( mbedtls_test_hexcmp( key, result_key_string->x,
                                      key_len, result_key_string->len ) == 0 );

exit:
    mbedtls_md_free( &ctx );
}

void test_pbkdf2_hmac_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};
    data_t data7 = {(uint8_t *) params[7], *( (uint32_t *) params[8] )};

    test_pbkdf2_hmac( *( (int *) params[0] ), &data1, &data3, *( (int *) params[5] ), *( (int *) params[6] ), &data7 );
}
#if defined(MBEDTLS_ASN1_PARSE_C)
void test_mbedtls_pkcs5_pbes2( int params_tag, data_t *params_hex, data_t *pw,
                  data_t *data, int ref_ret, data_t *ref_out )
{
    int my_ret;
    mbedtls_asn1_buf params;
    unsigned char *my_out = NULL;

    params.tag = params_tag;
    params.p = params_hex->x;
    params.len = params_hex->len;

    my_out = mbedtls_test_zero_alloc( ref_out->len );

    my_ret = mbedtls_pkcs5_pbes2( &params, MBEDTLS_PKCS5_DECRYPT,
                          pw->x, pw->len, data->x, data->len, my_out );
    TEST_ASSERT( my_ret == ref_ret );

    if( ref_ret == 0 )
        TEST_ASSERT( memcmp( my_out, ref_out->x, ref_out->len ) == 0 );

exit:
    mbedtls_free( my_out );
}

void test_mbedtls_pkcs5_pbes2_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};
    data_t data5 = {(uint8_t *) params[5], *( (uint32_t *) params[6] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};

    test_mbedtls_pkcs5_pbes2( *( (int *) params[0] ), &data1, &data3, &data5, *( (int *) params[7] ), &data8 );
}
#endif /* MBEDTLS_ASN1_PARSE_C */
#if defined(MBEDTLS_SELF_TEST)
void test_pkcs5_selftest(  )
{
    TEST_ASSERT( mbedtls_pkcs5_self_test( 1 ) == 0 );
exit:
    ;
}

void test_pkcs5_selftest_wrapper( void ** params )
{
    (void)params;

    test_pkcs5_selftest(  );
}
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_PKCS5_C */

/*----------------------------------------------------------------------------*/
/* Test dispatch code */


/**
 * \brief       Evaluates an expression/macro into its literal integer value.
 *              For optimizing space for embedded targets each expression/macro
 *              is identified by a unique identifier instead of string literals.
 *              Identifiers and evaluation code is generated by script:
 *              generate_test_code.py and then mbedtls_test_suite.sh and then mbedtls_test_suite.sh
 *
 * \param exp_id    Expression identifier.
 * \param out_value Pointer to int to hold the integer.
 *
 * \return       0 if exp_id is found. 1 otherwise.
 */
int get_expression( int32_t exp_id, int32_t * out_value )
{
    int ret = KEY_VALUE_MAPPING_FOUND;

    (void) exp_id;
    (void) out_value;

    switch( exp_id )
    {

#if defined(MBEDTLS_PKCS5_C)

        case 0:
            {
                *out_value = MBEDTLS_MD_SHA1;
            }
            break;
        case 1:
            {
                *out_value = MBEDTLS_MD_SHA224;
            }
            break;
        case 2:
            {
                *out_value = MBEDTLS_MD_SHA256;
            }
            break;
        case 3:
            {
                *out_value = MBEDTLS_MD_SHA384;
            }
            break;
        case 4:
            {
                *out_value = MBEDTLS_MD_SHA512;
            }
            break;
        case 5:
            {
                *out_value = MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE;
            }
            break;
        case 6:
            {
                *out_value = MBEDTLS_ASN1_SEQUENCE;
            }
            break;
        case 7:
            {
                *out_value = MBEDTLS_ERR_PKCS5_INVALID_FORMAT + MBEDTLS_ERR_ASN1_UNEXPECTED_TAG;
            }
            break;
        case 8:
            {
                *out_value = MBEDTLS_ERR_PKCS5_INVALID_FORMAT + MBEDTLS_ERR_ASN1_OUT_OF_DATA;
            }
            break;
        case 9:
            {
                *out_value = MBEDTLS_ERR_PKCS5_FEATURE_UNAVAILABLE;
            }
            break;
        case 10:
            {
                *out_value = MBEDTLS_ERR_PKCS5_INVALID_FORMAT + MBEDTLS_ERR_ASN1_LENGTH_MISMATCH;
            }
            break;
        case 11:
            {
                *out_value = MBEDTLS_ERR_PKCS5_INVALID_FORMAT;
            }
            break;
        case 12:
            {
                *out_value = MBEDTLS_ERR_PKCS5_PASSWORD_MISMATCH;
            }
            break;
#endif

        default:
           {
                ret = KEY_VALUE_MAPPING_NOT_FOUND;
           }
           break;
    }
    return( ret );
}


/**
 * \brief       Checks if the dependency i.e. the compile flag is set.
 *              For optimizing space for embedded targets each dependency
 *              is identified by a unique identifier instead of string literals.
 *              Identifiers and check code is generated by script:
 *              generate_test_code.py and then mbedtls_test_suite.sh and then mbedtls_test_suite.sh
 *
 * \param dep_id    Dependency identifier.
 *
 * \return       DEPENDENCY_SUPPORTED if set else DEPENDENCY_NOT_SUPPORTED
 */
int dep_check( int dep_id )
{
    int ret = DEPENDENCY_NOT_SUPPORTED;

    (void) dep_id;

    switch( dep_id )
    {

#if defined(MBEDTLS_PKCS5_C)

        case 0:
            {
#if defined(MBEDTLS_SHA1_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 1:
            {
#if defined(MBEDTLS_SHA256_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 2:
            {
#if defined(MBEDTLS_SHA512_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 3:
            {
#if !defined(MBEDTLS_SHA512_NO_SHA384)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 4:
            {
#if defined(MBEDTLS_DES_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 5:
            {
#if defined(MBEDTLS_CIPHER_MODE_CBC)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
#endif

        default:
            break;
    }
    return( ret );
}


/**
 * \brief       Function pointer type for test function wrappers.
 *
 * A test function wrapper decodes the parameters and passes them to the
 * underlying test function. Both the wrapper and the underlying function
 * return void. Test wrappers assume that they are passed a suitable
 * parameter array and do not perform any error detection.
 *
 * \param param_array   The array of parameters. Each element is a `void *`
 *                      which the wrapper casts to the correct type and
 *                      dereferences. Each wrapper function hard-codes the
 *                      number and types of the parameters.
 */
typedef void (*TestWrapper_t)( void **param_array );


/**
 * \brief       Table of test function wrappers. Used by dispatch_test().
 *              This table is populated by script:
 *              generate_test_code.py and then mbedtls_test_suite.sh and then mbedtls_test_suite.sh
 *
 */
TestWrapper_t test_funcs[] =
{
/* Function Id: 0 */

#if defined(MBEDTLS_PKCS5_C)
    test_pbkdf2_hmac_wrapper,
#else
    NULL,
#endif
/* Function Id: 1 */

#if defined(MBEDTLS_PKCS5_C) && defined(MBEDTLS_ASN1_PARSE_C)
    test_mbedtls_pkcs5_pbes2_wrapper,
#else
    NULL,
#endif
/* Function Id: 2 */

#if defined(MBEDTLS_PKCS5_C) && defined(MBEDTLS_SELF_TEST)
    test_pkcs5_selftest_wrapper,
#else
    NULL,
#endif

};

/**
 * \brief        Execute the test function.
 *
 *               This is a wrapper function around the test function execution
 *               to allow the setjmp() call used to catch any calls to the
 *               parameter failure callback, to be used. Calls to setjmp()
 *               can invalidate the state of any local auto variables.
 *
 * \param fp     Function pointer to the test function.
 * \param params Parameters to pass to the #TestWrapper_t wrapper function.
 *
 */
void execute_function_ptr(TestWrapper_t fp, void **params)
{
#if defined(MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG)
    mbedtls_test_enable_insecure_external_rng( );
#endif

#if defined(MBEDTLS_CHECK_PARAMS)
    mbedtls_test_param_failed_location_record_t location_record;

    if ( setjmp( mbedtls_test_param_failed_get_state_buf( ) ) == 0 )
    {
        fp( params );
    }
    else
    {
        /* Unexpected parameter validation error */
        mbedtls_test_param_failed_get_location_record( &location_record );
        mbedtls_test_fail( location_record.failure_condition,
                           location_record.line,
                           location_record.file );
    }

    mbedtls_test_param_failed_reset_state( );
#else
    fp( params );
#endif

#if defined(MBEDTLS_TEST_MUTEX_USAGE)
    mbedtls_test_mutex_usage_check( );
#endif /* MBEDTLS_TEST_MUTEX_USAGE */
}

/**
 * \brief        Dispatches test functions based on function index.
 *
 * \param func_idx    Test function index.
 * \param params      The array of parameters to pass to the test function.
 *                    It will be decoded by the #TestWrapper_t wrapper function.
 *
 * \return       DISPATCH_TEST_SUCCESS if found
 *               DISPATCH_TEST_FN_NOT_FOUND if not found
 *               DISPATCH_UNSUPPORTED_SUITE if not compile time enabled.
 */
int dispatch_test( size_t func_idx, void ** params )
{
    int ret = DISPATCH_TEST_SUCCESS;
    TestWrapper_t fp = NULL;

    if ( func_idx < (int)( sizeof( test_funcs ) / sizeof( TestWrapper_t ) ) )
    {
        fp = test_funcs[func_idx];
        if ( fp )
            execute_function_ptr(fp, params);
        else
            ret = DISPATCH_UNSUPPORTED_SUITE;
    }
    else
    {
        ret = DISPATCH_TEST_FN_NOT_FOUND;
    }

    return( ret );
}


/**
 * \brief       Checks if test function is supported in this build-time
 *              configuration.
 *
 * \param func_idx    Test function index.
 *
 * \return       DISPATCH_TEST_SUCCESS if found
 *               DISPATCH_TEST_FN_NOT_FOUND if not found
 *               DISPATCH_UNSUPPORTED_SUITE if not compile time enabled.
 */
int check_test( size_t func_idx )
{
    int ret = DISPATCH_TEST_SUCCESS;
    TestWrapper_t fp = NULL;

    if ( func_idx < (int)( sizeof(test_funcs)/sizeof( TestWrapper_t ) ) )
    {
        fp = test_funcs[func_idx];
        if ( fp == NULL )
            ret = DISPATCH_UNSUPPORTED_SUITE;
    }
    else
    {
        ret = DISPATCH_TEST_FN_NOT_FOUND;
    }

    return( ret );
}

int main( int argc, const char *argv[] )
{
    int ret;
    mbedtls_test_platform_setup();
    ret = execute_tests( argc, argv, "/zip/third_party/mbedtls/test/test_suite_pkcs5.datax" );
    mbedtls_test_platform_teardown();
    return( ret );
}
