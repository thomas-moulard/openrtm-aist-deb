// -*- C++ -*-
/*!
 * @file Listener.h
 * @brief Listener class
 * @date $Date: 2007-12-31 03:08:04 $
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2007
 *     Task-intelligence Research Group,
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id: Listener.h 826 2008-08-26 08:13:39Z n-ando $
 *
 */

#ifndef Listener_h
#define Listener_h


/*!
 * @if jp
 * @class ListenerBase
 * @brief ListenerBase �N���X
 *
 * �^�C�}�[�ɓo�^���郊�X�i�[�p���ۃC���^�[�t�F�[�X�N���X�B
 *
 * @since 0.4.0
 *
 * @else
 * @class ListenerBase
 * @brief ListenerBase class
 *
 * This is the abstract interface for Listener that registers
 * to the timer
 *
 * @since 0.4.0
 *
 * @endif
 */
class ListenerBase
{
public:
  /*!
   * @if jp
   * @brief �f�X�g���N�^
   *
   * �f�X�g���N�^
   *
   * @else
   * @brief Destructor
   *
   * Destructor
   *
   * @endif
   */
  virtual ~ListenerBase(){}
  
  /*!
   * @if jp
   * @brief �R�[���o�b�N����
   *
   * �R�[���o�b�N�����p�������z�֐�
   *
   * @else
   * @brief Callback
   *
   * Pure virtual function for callback-handling
   *
   * @endif
   */
  virtual void invoke() = 0;
};

/*!
 * @if jp
 * @class ListenerObject
 * @brief ListenerObject �N���X
 *
 * �^�C�}�[�ɓo�^���郊�X�i�[�p���N���X�B
 *
 * @since 0.4.0
 *
 * @else
 * @class ListenerObject
 * @brief ListenerObject class
 *
 * This is a base class for Listener that registers to the timer
 *
 * @since 0.4.0
 *
 * @endif
 */
template <class ListenerClass,
	  class CallbackFunc = void (ListenerClass::*)()>
class ListenerObject
  : public ListenerBase
{
public:
  /*!
   * @if jp
   * @brief �R���X�g���N�^
   *
   * �R���X�g���N�^
   *
   * @param obj ���X�i�[�I�u�W�F�N�g
   * @param cbf �R�[���o�b�N�p�֐�
   *
   * @else
   * @brief Constructor
   *
   * Constructor
   *
   * @param obj Listener Object
   * @param cbf Callback Function
   *
   * @endif
   */
  ListenerObject(ListenerClass* obj, CallbackFunc cbf)
    : m_obj(obj), m_cbf(cbf)
  {
  }
  
  /*!
   * @if jp
   * @brief �f�X�g���N�^
   *
   * �f�X�g���N�^
   *
   * @else
   * @brief Destructor
   *
   * Destructor
   *
   * @endif
   */
  virtual ~ListenerObject()
  {
  }
  
  /*!
   * @if jp
   * @brief �R�[���o�b�N�p����
   *
   * �R�[���o�b�N�����p�֐�
   *
   * @else
   * @brief Callback
   *
   * Callback function
   *
   * @endif
   */
  virtual void invoke()
  {
    (m_obj->*m_cbf)();
  }
  
private:
  ListenerClass* m_obj;
  CallbackFunc m_cbf;
};

/*!
 * @if jp
 * @class ListenerFunc
 * @brief ListenerFunc �N���X
 *
 * �R�[���o�b�N�p�I�u�W�F�N�g�B
 *
 * @since 0.4.0
 *
 * @else
 * @class ListenerFunc
 * @brief ListenerFunc class
 *
 * Callback object
 *
 * @since 0.4.0
 *
 * @endif
 */
typedef void (*CallbackFunc)();
class ListenerFunc
  : public ListenerBase
{
public:
  /*!
   * @if jp
   * @brief �R���X�g���N�^
   *
   * �R���X�g���N�^
   *
   * @param cbf �R�[���o�b�N�p�֐�
   *
   * @else
   * @brief Constructor
   *
   * Constructor
   *
   * @param cbf Callback Function
   *
   * @endif
   */
  ListenerFunc(CallbackFunc cbf)
    : m_cbf(cbf)
  {
  }
  
  /*!
   * @if jp
   * @brief �f�X�g���N�^
   *
   * �f�X�g���N�^
   *
   * @else
   * @brief Destructor
   *
   * Destructor
   *
   * @endif
   */
  virtual ~ListenerFunc(){}
  
  /*!
   * @if jp
   * @brief �R�[���o�b�N����
   *
   * �R�[���o�b�N�����p�֐�
   *
   * @else
   * @brief Callback
   *
   * Callback function
   *
   * @endif
   */
  virtual void invoke()
  {
    (*m_cbf)();
  }
  
private:
  CallbackFunc m_cbf;
};

#endif // Listener_h
