// -*- C++ -*-
/*!
 * @file  Guard.h
 * @brief Guard template class
 * @date  $Date$
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2008
 *     Noriaki Ando
 *     Task-intelligence Research Group,
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id$
 *
 */

#ifndef COIL_GUARD_H
#define COIL_GUARD_H

#include <coil/Mutex.h>

namespace coil
{
  /*!
   * @if jp
   *
   * @class Guard
   * @brief Guard �e���v���[�g�N���X
   *
   * @else
   *
   * @class Guard
   * @brief Guard template class
   *
   * @endif
   */
  template <class M>
  class Guard
  {
  public:

    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^
     *
     * �R���X�g���N�^�B
     *
     * @param mutex �X���b�h
     *
     * @else
     *
     * @brief Constructor
     *
     * Constructor
     *
     * @param mutex pthread
     *
     * @endif
     */
    Guard(M& mutex) : m_mutex(mutex)
    {
      m_mutex.lock();
    }

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
    ~Guard()
    {
      m_mutex.unlock();
    }

  private:
    Guard(const Guard&);
    Guard& operator=(const Guard&);
    M& m_mutex;
  };
};
#endif // COIL_GUARD_H
