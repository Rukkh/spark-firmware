/**
 ******************************************************************************
 * @file    concurrency_hal.h
 * @authors Matthew McGowan
 * @date    03 March 2015
 ******************************************************************************
  Copyright (c) 2015 Particle Industries, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

#ifndef CONCURRENCY_HAL_H
#define	CONCURRENCY_HAL_H

#if PLATFORM_THREADING

#include <stdint.h>
#include <stddef.h>
/**
 * Allow specific HAL implementations to export key symbols:
 * - thread priority limits and type.
 * - default stack size
 * 
 */
#include "concurrent_hal_impl.h"


typedef void* os_thread_t;

const os_thread_t OS_THREAD_INVALID_HANDLE = NULL;

/**
 * The return type from a thread function.
 */
typedef void os_thread_return_t;

/**
 * The start function for a new thread.
 */
typedef os_thread_return_t (*os_thread_fn_t)(void* param);

/**
 * Creates a new thread. 
 * @param result            Receives the created thread handle. Will be set to NULL if the thread cannot be created.
 * @param name              The name of the thread. May be used if the underlying RTOS supports it. Can be null.
 * @param priority          The thread priority. It's best to stick to a small range of priorities, e.g. +/- 7.
 * @param fun               The function to execute in a separate thread.
 * @param thread_param      The parameter to pass to the thread function.
 * @param stack_size        The size of the stack to create. The stack is allocated on the heap. 
 * @return an error code. 0 if the thread was successfully created.
 */
os_result_t os_thread_create(os_thread_t* result, const char* name, 
        os_thread_prio_t priority, os_thread_fn_t fun, void* thread_param, 
        size_t stack_size);

/**
 * 
 * @param result            Receives the created thread handle. Will be set to NULL if the thread cannot be created.
 * @param name              The name of the thread. May be used if the underlying RTOS supports it.
 * @param priority          The thread priority. It's best to stick to a small range of priorities, e.g. +/- 7.
 * @param fun               The function to execute in a separate thread.
 * @param thread_param      The parameter to pass to the thread function.
 * @param stack_size        The size of the stack to create. The stack is allocated on the heap. 
 * @param stack             The location of the bottom of the stack. The top of the stack is at location stack + stack_size.
 */
os_result_t os_thread_create_with_stack(os_thread_t* result, const char* name, 
        os_thread_prio_t priority, os_thread_fn_t fun, void* thread_param, 
        size_t stack_size, void* stack);

/**
 * Determines if the given thread is the one executing.
 * @param   The thread to test.
 * @return {@code true} if the thread given is the one currently executing. {@code false} otherwise.
 */
bool os_thread_is_current(os_thread_t thread);

/**
 * Determines if the thread stack is still within the allocated region.
 * @param thread    The thread to check
 * @return      {@code true} if the thread is still within the allocated stack region.
 *  {@code false} if the thread has gone through the bottom of the stack. Depending upon where the stack was
 *  allocated this may cause corruption of system or user data. As a precaution, the device should be reset unless
 * measures have been taken to ensure the region of memory the stack grows into is unused (such as overallocating the stack size.)
 */
bool os_thread_is_current_within_stack();

/**
 * Waits indefinitely for the given thread to finish.
 * @param thread    The thread to wait for.
 * @return 0 if the thread has successfully terminated. non-zero if the thread handle is not valid.
 */
os_result_t os_thread_join(os_thread_t thread);

/**
 * Cleans up resources used by a terminated thread.
 * @param thread    The thread to clean up.
 * @return 0 on success.
 */
os_result_t os_thread_cleanup(os_thread_t thread);

#endif

#endif	/* CONCURRENCY_HAL_H */

