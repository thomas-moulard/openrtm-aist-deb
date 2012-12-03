// -*- C++ -*-
/*!
 * @file  Allocator.h
 * @brief Memory allocator class
 * @date  $Date$
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2009
 *     Noriaki Ando
 *     Task-intelligence Research Group,
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id: PublisherPeriodic.h 1225 2009-02-28 02:30:25Z n-ando $
 *
 */

#ifndef COIL_ALLOCATOR_H
#define COIL_ALLOCATOR_H

#include <stddef.h>
#include <new>
#include <coil/Singleton.h>

namespace coil
{
  /*!
   * @if jp
   *
   * @class Allocator
   * @brief Allocator �N���X
   *
   * @else
   *
   * @class Allocator
   * @brief Allocator class
   *
   * @endif
   */
  class Allocator
    : public Singleton<Allocator>
  {
  public:
    /*!
     * @if jp
     *
     * @brief �f�X�g���N�^
     *
     * �f�X�g���N�^�B
     *
     * @else
     *
     * @brief Destructor
     *
     * Destructor
     *
     * @endif
     */
    virtual ~Allocator(){};

    /*!
     * @if jp
     *
     * @brief �������̈�m��
     *
     * �������̈���m�ۂ���B
     *
     * @param t ���蓖�ăT�C�Y
     *
     * @return �������̈�ւ̃|�C���^
     *
     * @else
     *
     * @brief Create of memory allocation
     *
     * Create of memory allocation.
     *
     * @param t Allocation size.
     *
     * @return Pointer to a memory allocation.
     *
     * @endif
     */
    virtual void* New(size_t t) throw (std::bad_alloc);

    /*!
     * @if jp
     *
     * @brief �������̈���
     *
     * �������̈���������B
     *
     * @param p �������̈�ւ̃|�C���^
     *
     * @else
     *
     * @brief Delete of memory allocation
     *
     * Delete of memory allocation.
     *
     * @param p Pointer to a memory allocation.
     *
     * @endif
     */
    virtual void Delete(void* p) throw ();

    /*!
     * @if jp
     *
     * @brief �z��p�������̈�m��
     *
     * �z��p�������̈���m�ۂ���B
     *
     * @param t ���蓖�ăT�C�Y
     *
     * @return �������̈�ւ̃|�C���^
     *
     * @else
     *
     * @brief Create of array memory allocation
     *
     * Create of array memory allocation.
     *
     * @param t Allocation size.
     *
     * @return Pointer to a memory allocation.
     *
     * @endif
     */
    virtual void* NewArray(size_t t) throw (std::bad_alloc);

    /*!
     * @if jp
     *
     * @brief �z��p�������̈���
     *
     * �z��p�������̈���������B
     *
     * @param p �������̈�ւ̃|�C���^
     *
     * @else
     *
     * @brief Delete of array memory allocation
     *
     * Delete of array memory allocation.
     *
     * @param p Pointer to a memory allocation.
     *
     * @endif
     */
    virtual void DeleteArray(void* p) throw ();

  };
};
#endif // COIL_ALLOCATOR_H
