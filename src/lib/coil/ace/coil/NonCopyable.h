// -*- C++ -*-
/*!
 * @file  NonCopyable.h
 * @brief Non Copyable mixin class
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

namespace coil
{
  /*!
   * @if jp
   * @class NonCopyable
   * @brief �R�s�[�֎~�~�b�N�X�C��
   * 
   * �ΏۃN���X�̃I�u�W�F�N�g�̃R�s�[���֎~����B�R�s�[���֎~�������N��
   * �X�ł́ANonCopyable��private�p�����邱�ƂŃI�u�W�F�N�g�̃R�s�[����
   * �~���邱�Ƃ��ł���B
   *
   * -��:
   * class CopyProhibitedClass : private NonCopyable {};
   *
   * @else
   *
   * @class NonCopyable
   * @brief Non-copyable Mixin
   *
   * This mix-in class prevents objects of a class from being
   * copy-constructed or assigned to each other. User can prohibit the
   * class copying by inheriting from NonCopyable class as a private
   * base class.
   *
   * -example:
   * class CopyProhibitedClass : private NonCopyable {};
   *
   * @endif
   */
  class NonCopyable
  {
  protected:
    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^
     *
     * �R���X�g���N�^�B
     *
     * @else
     *
     * @brief Constructor
     *
     * Constructor
     *
     * @endif
     */
    NonCopyable() {}

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
    ~NonCopyable() {}
  private:
    NonCopyable(const NonCopyable&);
    NonCopyable& operator=(const NonCopyable&);
  };

  /*!
   * @if jp
   * @class NonCopyableCRTP
   * @brief �R�s�[�֎~�~�b�N�X�C��(CRTP��)
   * 
   * �ΏۃN���X�̃I�u�W�F�N�g�̃R�s�[���֎~����B�R�s�[���֎~�������N��
   * �X�ł́ANonCopyable��private�p�����邱�ƂŃI�u�W�F�N�g�̃R�s�[����
   * �~���邱�Ƃ��ł���B����CRTP (Curiously Recursive Template
   * Pattern) �ł́A��̊��N���X�ɑ΂���œK�� (Empty Base
   * Optimization) ���s�킹�����ꍇ�ɗ��p����B
   *
   * -��:
   * struct A : NonCopyableCRTP<A> {};
   * struct B : NonCopyableCRTP<B> {};
   * struct C: A, B {};
   *
   * @else
   *
   * @class NonCopyable
   * @brief Non-copyable Mixin
   *
   * This mix-in class prevents objects of a class from being
   * copy-constructed or assigned to each other. User can prohibit the
   * class copying by inheriting from NonCopyable class as a private
   * base class.�@The CRTP (Curiously Recursive Template Pattern)
   * version would be used for empty base optimization for
   * multipe-inherited.
   *
   * -example:
   * class CopyProhibitedClass : private NonCopyable {};
   *
   * @endif
   */
  template <class T>
  class NonCopyableCRTP
  {
  protected:
    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^
     *
     * �R���X�g���N�^�B
     *
     * @else
     *
     * @brief Constructor
     *
     * Constructor
     *
     * @endif
     */
    NonCopyableCRTP() {}

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
    ~NonCopyableCRTP() {}
  private: 
    NonCopyableCRTP(const NonCopyableCRTP &);
    T & operator=(const T &);
  };
};
