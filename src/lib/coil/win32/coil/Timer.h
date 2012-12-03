// -*- C++ -*-
/*!
 * @file Timer.h
 * @brief Timer class
 * @date $Date: 2007-04-26 15:34:05 $
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2007-2008
 *     Task-intelligence Research Group,
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id: Timer.h 826 2008-08-26 08:13:39Z n-ando $
 *
 */

#ifndef Timer_h
#define Timer_h

#include <coil/TimeValue.h>
#include <coil/Listener.h>
#include <coil/Mutex.h>
#include <coil/Guard.h>
#include <coil/Task.h>
#include <vector>

typedef ListenerBase* ListenerId;

namespace coil
{
  /*!
   * @if jp
   * @class Timer
   * @brief Timer�N���X
   * 
   * �o�^���ꂽ���X�i�[�̃R�[���o�b�N�֐����A�ݒ肳�ꂽ�����Œ���I�ɌĂяo���B
   *
   * @since 0.4.0
   *
   * @else
   * @class Timer
   * @brief Timer class
   * 
   * Invoke the callback function of registered listener periodically
   * at the set cycle.
   *
   * @since 0.4.0
   *
   * @endif
   */
  class Timer
    : public coil::Task
  {
    typedef coil::Mutex Mutex;
    typedef coil::Guard<Mutex> Guard;
  public:
    /*!
     * @if jp
     * @brief �R���X�g���N�^
     * 
     * �R���X�g���N�^
     *
     * @param interval �^�C�}�N������
     *
     * @else
     * @brief Constructor
     * 
     * Constructor
     *
     * @param interval The interval of timer
     *
     * @endif
     */
    Timer(TimeValue& interval);
    
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
    virtual ~Timer();
    
    //============================================================
    // ACE_Task 
    //============================================================
    /*!
     * @if jp
     * @brief Timer �p�X���b�h����
     *
     * Timer �p�̓����X���b�h�𐶐����N������B
     * ����� ACE_Task �T�[�r�X�N���X���\�b�h�̃I�[�o�[���C�h�B
     *
     * @param args �ʏ��0
     *
     * @return �����������s����
     *
     * @else
     * @brief Create thread for Timer
     *
     * Create an internal thread for Timer and launch it.
     * This is an override of ACE_Task service class method.
     *
     * @param args Usually 0
     *
     * @return Creation processing result
     *
     * @endif
     */     
    virtual int open(void *args);
    
    /*!
     * @if jp
     * @brief Timer �p�̃X���b�h���s�֐�
     *
     * Timer �p�̃X���b�h���s�֐��B
     * �o�^���ꂽ���X�i�[�̃R�[���o�b�N�֐����Ăяo���B
     *
     * @return ���s����
     *
     * @else
     * @brief Thread execution function for Timer
     *
     * Thread execution function for Timer.
     * Invoke the callback function of registered listener.
     *
     * @return Execution result
     *
     * @endif
     */     
    virtual int svc(void);
    
    //============================================================
    // public functions
    //============================================================
    /*!
     * @if jp
     * @brief Timer �^�X�N�J�n
     *
     * Timer �p�V�K�X���b�h�𐶐����A�������J�n����B
     *
     * @else
     * @brief Start Timer task
     *
     * Create a new theread for Timer and start processing.
     *
     * @endif
     */
    void start();
    
    /*!
     * @if jp
     * @brief Timer �^�X�N��~
     *
     * Timer �^�X�N���~����B
     *
     * @else
     * @brief Stop Timer task
     *
     * Stop Timer task.
     *
     * @endif
     */
    void stop();
    
    /*!
     * @if jp
     * @brief Timer �^�X�N���s
     *
     * �o�^���ꂽ�e���X�i�̋N���҂����Ԃ���^�C�}�N�����������Z����B
     * �N���҂����Ԃ��[���ƂȂ������X�i�����݂���ꍇ�́A
     * �R�[���o�b�N�֐����Ăяo���B
     *
     * @else
     * @brief Invoke Timer task
     *
     * Subtract the interval of timer from the waiting time for invocation
     * of each registered listener.
     * If the listener whose waiting time reached 0 exists, invoke the
     * callback function.
     *
     * @endif
     */
    void invoke();
    
    /*!
     * @if jp
     * @brief ���X�i�[�o�^
     *
     * �{ Timer ����N������R�[���o�b�N�֐��p�̃��X�i�[���N���������w�肵��
     * �o�^����B
     * ���ꃊ�X�i�[�����ɓo�^�ς݂̏ꍇ�́A���X�i�[�̋N���������w�肵���l��
     * �X�V����B
     *
     * @param listener �o�^�Ώۃ��X�i�[
     * @param tm ���X�i�[�N������
     *
     * @return �o�^���X�i�[ID
     *
     * @else
     * @brief Register listener
     *
     * Register the listener of callback function invoked from this Timer by
     * specifying the interval.
     * If the same listener has already been regiseterd, the value specified
     * the invocation interval of listener will be updated.
     * 
     *
     * @param listener Listener for the registration
     * @param tm The invocation interval of listener
     *
     * @return ID of the registerd listener
     *
     * @endif
     */
    ListenerId registerListener(ListenerBase* listener, TimeValue tm);
    
    /*!
     * @if jp
     * @brief ���X�i�[�o�^
     *
     * �R�[���o�b�N�ΏۃI�u�W�F�N�g�A�R�[���o�b�N�Ώۃ��\�b�h����ыN��������
     * �w�肵�ă��X�i�[��o�^����B
     *
     * @param obj �R�[���o�b�N�ΏۃI�u�W�F�N�g
     * @param cbf �R�[���o�b�N�Ώۃ��\�b�h
     * @param tm ���X�i�[�N������
     *
     * @return �o�^���X�i�[ID
     *
     * @else
     * @brief Register listener
     *
     * Register listener by specifying the object for callback, the method
     * for callback and the invocation interval.
     *
     * @param obj Target object for callback
     * @param cbf Target method for callback
     * @param tm The invocation interval of listener
     *
     * @return ID of the registerd listener
     *
     * @endif
     */
    template <class ListenerClass>
    ListenerId registerListenerObj(ListenerClass* obj,
				   void (ListenerClass::*cbf)(),
				   TimeValue tm)
    {
      return registerListener(new ListenerObject<ListenerClass>(obj, cbf), tm);
    }
    
    /*!
     * @if jp
     * @brief ���X�i�[�o�^
     *
     * �R�[���o�b�N�Ώۃ��\�b�h�ƋN���������w�肵�ă��X�i�[��o�^����B
     *
     * @param cbf �R�[���o�b�N�Ώۃ��\�b�h
     * @param tm ���X�i�[�N������
     *
     * @return �o�^���X�i�[ID
     *
     * @else
     * @brief Register listener
     *
     * Register listener by specifying the method for callback and the
     * invocation interval.
     *
     * @param cbf Target method for callback
     * @param tm The invocation interval of listener
     *
     * @return ID of the registerd listener
     *
     * @endif
     */
    ListenerId registerListenerFunc(void (*cbf)(), TimeValue tm)
    {
      return registerListener(new ListenerFunc(cbf), tm);
    }
    
    /*!
     * @if jp
     * @brief ���X�i�[�o�^����
     *
     * �w�肵��ID�̃��X�i�[�̓o�^����������B
     * �w�肵��ID�̃��X�i�[�����o�^�̏ꍇ�Afalse ��Ԃ��B
     *
     * @param id �o�^�����Ώۃ��X�i�[ID
     *
     * @return �o�^��������
     *
     * @else
     * @brief Unregister listener
     *
     * Unregister the listener specified by ID.
     * If the listener specified by ID is not registerd, false will be returned.
     *
     * @param id ID of the unregisterd listener
     *
     * @return Unregistration result
     *
     * @endif
     */
    bool unregisterListener(ListenerId id);
    
  private:
    TimeValue m_interval;
    
    Mutex m_runningMutex;
    bool m_running;
    
    struct Task
    {
      Task(ListenerBase* l, TimeValue p)
	: listener(l), period(p), remains(p)
      {
      }
      ListenerBase* listener;
      TimeValue period;
      TimeValue remains;
    };
    
    std::vector<Task> m_tasks;
    Mutex  m_taskMutex;
  };
};
#endif // Timer_h

