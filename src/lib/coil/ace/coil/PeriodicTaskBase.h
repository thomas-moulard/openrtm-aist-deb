// -*- C++ -*-
/*!
 * @file PeriodicTaskBase.h
 * @brief TaskFuncBase TaskFunc PeriodicTaskBase class
 * @date $Date$
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
 * $Id$
 *
 */

#ifndef COIL_PERIODICTASKBASE_H
#define COIL_PERIODICTASKBASE_H

#include <coil/TimeValue.h>
#include <coil/TimeMeasure.h>
#include <coil/Task.h>

namespace coil
{
  /*!
   * @if jp
   *
   * @class TaskFuncBase
   * @brief TaskFuncBase �N���X
   *
   * @else
   *
   * @class TaskFuncBase
   * @brief TaskFuncBase class
   *
   * @endif
   */
  class TaskFuncBase
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
    virtual ~TaskFuncBase() {}

    /*!
     * @if jp
     *
     * @brief �I�u�W�F�N�g�̊֐����s�p�������z�֐�
     *
     * �I�u�W�F�N�g�̊֐����s�p�������z�֐��B
     *
     * @else
     *
     * @brief Functor
     *
     * Pure virtual function for Functor.
     *
     * @endif
     */
    virtual int operator()() = 0;
  };
  
  /*!
   * @if jp
   *
   * @class TaskFunc
   * @brief TaskFunc �e���v���[�g�N���X
   *
   * @else
   *
   * @class TaskFunc
   * @brief TaskFunc template class
   *
   * @endif
   */
  template <typename T, typename F = int (*)()>
  class TaskFunc
    : public TaskFuncBase
  {
  public:
    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^
     *
     * �R���X�g���N�^�B
     *
     * @param obj �I�u�W�F�N�g
     * @param func �֐�
     *
     * @else
     *
     * @brief Constructor
     *
     * Constructor
     *
     * @param obj Object.
     * @param func Function.
     *
     * @endif
     */
    TaskFunc(T* obj, F func)
      : m_obj(obj), m_func(func)
    {
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
    virtual ~TaskFunc() {}

    /*!
     * @if jp
     *
     * @brief �I�u�W�F�N�g�̊֐����s
     *
     * �I�u�W�F�N�g�̊֐������s����B
     *
     * @else
     *
     * @brief Functor
     *
     * Execute a function of the object.
     *
     * @endif
     */
    virtual int operator()()
    {
      return (m_obj->*m_func)();
    }

    /*!
     * @if jp
     * @brief �I�u�W�F�N�g
     * @else
     * @brief object
     * @endif
     */
    T* m_obj;

    /*!
     * @if jp
     * @brief �֐�
     * @else
     * @brief function
     * @endif
     */
    F m_func;
  };

  /*!
   * @if jp
   *
   * @class PeriodicTaskBase
   * @brief PeriodicTaskBase �N���X
   *
   * @else
   *
   * @class PeriodicTaskBase
   * @brief PeriodicTaskBase class
   *
   * @endif
   */
  class PeriodicTaskBase
    : public coil::Task
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
    virtual ~PeriodicTaskBase(){};

    /*!
     * @if jp
     *
     * @brief �^�X�N���s���J�n���鏃�����z�֐�
     *
     * �^�X�N���s���J�n���鏃�����z�֐��B
     *
     * @else
     *
     * @brief Starting the task
     *
     * Pure virtual function for starting the task.
     *
     * @endif
     */
    virtual void activate() = 0;

    /*!
     * @if jp
     *
     * @brief �^�X�N���s���I�����鏃�����z�֐�
     *
     * �^�X�N���s���I�����鏃�����z�֐��B
     *
     * @else
     *
     * @brief Finalizing the task
     *
     * Pure virtual function for finalizing the task.
     *
     * @endif
     */
    virtual void finalize() = 0;

    /*!
     * @if jp
     *
     * @brief �^�X�N���s�𒆒f���鏃�����z�֐�
     *
     * �^�X�N���s�𒆒f���鏃�����z�֐��B
     *
     * @else
     *
     * @brief Suspending the task
     *
     * Pure virtual function for suspending the task.
     *
     * @endif
     */
    virtual int suspend(void) = 0;

    /*!
     * @if jp
     *
     * @brief ���f����Ă���^�X�N���ĊJ���鏃�����z�֐�
     *
     * ���f����Ă���^�X�N���ĊJ���鏃�����z�֐��B
     *
     * @else
     *
     * @brief Resuming the suspended task
     *
     * Pure virtual function for resuming the suspended task.
     *
     * @endif
     */
    virtual int resume(void) = 0;

    /*!
     * @if jp
     *
     * @brief ���f����Ă���^�X�N��1�����������s���鏃�����z�֐�
     *
     * ���f����Ă���^�X�N��1�����������s���鏃�����z�֐��B
     *
     * @else
     *
     * @brief Executing the suspended task one tick
     *
     * Pure virtual function for executing the suspended task one tick.
     *
     * @endif
     */
    virtual void signal() = 0;

    /*!
     * @if jp
     *
     * @brief �^�X�N���s�֐����Z�b�g���鏃�����z�֐�
     *
     * �^�X�N���s�֐����Z�b�g���鏃�����z�֐��B
     *
     * @param func �֐�
     * @param delete_in_dtor �폜�t���O
     *
     * @else
     *
     * @brief Setting task execution function
     *
     * Pure virtual function for setting task execution function.
     *
     * @param func Function.
     * @param delete_in_dtor Delete flag.
     *
     * @endif
     */
    virtual bool setTask(TaskFuncBase* func, bool delete_in_dtor = true) = 0;

    /*!
     * @if jp
     *
     * @brief �^�X�N���s�֐����Z�b�g����
     *
     * �^�X�N���s�֐����Z�b�g����
     *
     * @param obj �I�u�W�F�N�g
     * @param fun �֐�
     *
     * @return true: ����, false: ���s
     *
     * @else
     *
     * @brief Setting task execution function
     *
     * Pure virtual function for setting task execution function.
     *
     * @param obj Object.
     * @param fun Function.
     *
     * @return true: successful, false: failed
     *
     * @endif
     */
    template <class O, class F>
    bool setTask(O* obj, F fun)
    {
      return this->setTask(new TaskFunc<O, F>(obj, fun));
    }

    /*!
     * @if jp
     *
     * @brief �^�X�N���s�������Z�b�g���鏃�����z�֐�
     *
     * �^�X�N���s�������Z�b�g���鏃�����z�֐��B
     *
     * @param period ���s����
     *
     * @else
     *
     * @brief Setting task execution period
     *
     * Pure virtual function for setting task execution period.
     *
     * @param period Execution period.
     *
     * @endif
     */
    virtual void setPeriod(double period) = 0;

    /*!
     * @if jp
     *
     * @brief �^�X�N���s�������Z�b�g���鏃�����z�֐�
     *
     * �^�X�N���s�������Z�b�g���鏃�����z�֐��B
     *
     * @param period ���s����
     *
     * @else
     *
     * @brief Setting task execution period
     *
     * Pure virtual function for setting task execution period.
     *
     * @param period Execution period.
     *
     * @endif
     */
    virtual void setPeriod(coil::TimeValue& period) = 0;

    /*!
     * @if jp
     *
     * @brief �^�X�N�֐����s���Ԍv����L���ɂ��鏃�����z�֐�
     *
     * �^�X�N�֐����s���Ԍv����L���ɂ��鏃�����z�֐��B
     *
     * @param value �t���O(true: �L��, false: ����)
     *
     * @else
     *
     * @brief Validate a Task execute time measurement
     *
     * Pure virtual function for validate a Task execute time measurement.
     *
     * @param value flag(true: Valid, false: Invalid).
     *
     * @endif
     */
    virtual void executionMeasure(bool value) = 0;

    /*!
     * @if jp
     *
     * @brief �^�X�N�֐����s���Ԍv�������p�������z�֐�
     *
     * �^�X�N�֐����s���Ԍv�������p�������z�֐��B
     *
     * @param n �v������
     *
     * @else
     *
     * @brief Task execute time measurement period
     *
     * Pure virtual function for task execute time measurement period.
     *
     * @param n Measurement period.
     *
     * @endif
     */
    virtual void executionMeasureCount(int n) = 0;

    /*!
     * @if jp
     *
     * @brief �^�X�N�������Ԍv����L���ɂ��鏃�����z�֐�
     *
     * �^�X�N�������Ԍv����L���ɂ��鏃�����z�֐��B
     *
     * @param value �t���O(true: �L��, false: ����)
     *
     * @else
     *
     * @brief Validate a Task period time measurement
     *
     * Pure virtual function for validate a Task period time measurement.
     *
     * @param value flag(true: Valid, false: Invalid).
     *
     * @endif
     */
    virtual void periodicMeasure(bool value) = 0;

    /*!
     * @if jp
     *
     * @brief �^�X�N�������Ԍv�������p�������z�֐�
     *
     * �^�X�N�������Ԍv�������p�������z�֐��B
     *
     * @param n �v������
     *
     * @else
     *
     * @brief Task period time measurement count
     *
     * Pure virtual function for task period time measurement count.
     *
     * @param n Measurement period.
     *
     * @endif
     */
    virtual void periodicMeasureCount(int n) = 0;

    /*!
     * @if jp
     *
     * @brief �^�X�N�֐����s���Ԍv�����ʂ��擾���鏃�����z�֐�
     *
     * �^�X�N�֐����s���Ԍv�����ʂ��擾���鏃�����z�֐��B
     *
     * @else
     *
     * @brief Get a result in task execute time measurement
     *
     * Pure virtual function for get a result in task execute time measurement.
     *
     * @endif
     */
    virtual coil::TimeMeasure::Statistics getExecStat() = 0;

    /*!
     * @if jp
     *
     * @brief �^�X�N�������Ԍv�����ʂ��擾���鏃�����z�֐�
     *
     * �^�X�N�������Ԍv�����ʂ��擾���鏃�����z�֐��B
     *
     * @else
     *
     * @brief Get a result in task period time measurement
     *
     * Pure virtual function for get a result in task period time measurement.
     *
     * @endif
     */
    virtual coil::TimeMeasure::Statistics getPeriodStat() = 0;

  };
}; // namespace coil

#endif // COIL_PERIODICTASKBASE_H
