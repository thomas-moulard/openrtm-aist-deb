// -*- C++ -*-
/*!
 * @file PeriodicTask.h
 * @brief PeriodicTask class
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

#ifndef COIL_PERIODICTASK_H
#define COIL_PERIODICTASK_H

#include <map>
#include <string>
#include <vector>
#include <algorithm>

#include <coil/Mutex.h>
#include <coil/Guard.h>
#include <coil/Condition.h>
#include <coil/TimeValue.h>
#include <coil/TimeMeasure.h>
#include <coil/PeriodicTaskBase.h>

namespace coil
{
  /*!
   * @if jp
   * @class PeriodicTask
   * @brief �����^�X�N�X���b�h���s�N���X
   *
   * ����̊֐����������s���邽�߂̃X���b�h�I�u�W�F�N�g����������B
   * �g�p�菇�͈ȉ��̒ʂ�B
   *
   * task; // �C���X�^���X����
   * task.setTask(TaskFuncBase(obj, mem_func)); // ���s����֐���^����
   * task.activate(); // �X���b�h���X�^�[�g������
   *
   * task.suspend(); // �������s���~�߂�
   * task.signal(); // 1�����������s
   * task.resume(); // �������s���ĊJ
   *
   * task.finalize(); // �^�X�N���I��������
   * 
   * @else
   * @class PeriodicTask
   * @brief PeriodicTask class
   *
   * @endif
   */
  class PeriodicTask
    : public coil::PeriodicTaskBase
  {
  public:
    typedef coil::Guard<coil::Mutex> Guard;

    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^
     *
     * �R���X�g���N�^
     *
     * @else
     *
     * @brief Constructor
     *
     * Constructor
     *
     * @endif
     */
    PeriodicTask();
    
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
    virtual ~PeriodicTask();
    
    /*!
     * @if jp
     * @brief �^�X�N���s���J�n����
     *
     * �^�X�N�̎��s���J�n���邽�߂ɃX���b�h���X�^�[�g������B  �^�X�N��
     * ����ɊJ�n���ꂽ�ꍇ�� true ���Ԃ�A���łɃ^�X�N���J�n�ς݁A�܂�
     * �͎��s����^�X�N���ݒ肳��Ă��Ȃ���� false ��Ԃ��B
     *
     * @return true: ����J�n�Afalse: �X���b�h�ς݂��^�X�N�����ݒ�ł���B
     *
     * @else
     * @brief Starting the task
     *
     * Starting a thread to execute a task.  If the task/thread is
     * started properly, it will return 'TRUE'.  if the task/thread
     * are already started or task function object is not set, 'FALSE'
     * will be returned.
     *
     * @return true: normal start, false: already started  or task is not set
     *
     * @endif
     */
    virtual void activate();

    /*!
     * @if jp
     * @brief �^�X�N���s���I������
     *
     * ���s���̃^�X�N���I������B
     *
     * @else
     * @brief Finalizing the task
     *
     * Finalizing the task running.
     *
     * @endif
     */
    virtual void finalize();

    /*!
     * @if jp
     * @brief �^�X�N���s�𒆒f����
     *
     * ���s���̃^�X�N�𒆒f����B
     *
     * @else
     * @brief Suspending the task
     *
     * Suspending the task running.
     *
     * @endif
     */
    virtual int suspend(void);

    /*!
     * @if jp
     * @brief ���f����Ă���^�X�N���ĊJ����
     *
     * ���f����Ă���^�X�N���ĊJ����
     *
     * @else
     * @brief Resuming the suspended task
     *
     * Resuming the suspended task
     *
     * @endif
     */
    virtual int resume(void);

    /*!
     * @if jp
     * @brief ���f����Ă���^�X�N��1�����������s����
     *
     * ���f����Ă���^�X�N��1�����������s����
     *
     * @else
     * @brief Executing the suspended task one tick
     *
     * Executing the suspended task one tick
     *
     * @endif
     */
    virtual void signal();

    /*!
     * @if jp
     * @brief �^�X�N���s�֐����Z�b�g����
     *
     * @param func int (*)() �^�̊֐��|�C���^
     *
     * @else
     * @brief Setting task execution function
     *
     * @param func Set int (*)() type function pointer
     *
     * @endif
     */
    virtual bool setTask(TaskFuncBase* func, bool delete_in_dtor = true);

    /*!
     * @if jp
     * @brief �^�X�N���s�֐����Z�b�g����
     *
     * @param func int (*)() �^�̊֐��|�C���^
     *
     * @return true: ����, false: ���s
     *
     * @else
     * @brief Setting task execution function
     *
     * @param func Set int (*)() type function pointer
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
     * @brief �^�X�N���s�������Z�b�g����
     *
     * @param period ���s���� [sec]
     *
     * @else
     * @brief Setting task execution period
     *
     * @param period Execution period [sec]
     *
     * @endif
     */
    virtual void setPeriod(double period);

    /*!
     * @if jp
     * @brief �^�X�N���s�������Z�b�g����
     *
     * @param period ���s����
     *
     * @else
     * @brief Setting task execution period
     *
     * @param period Execution period
     *
     * @endif
     */
    virtual void setPeriod(TimeValue& period);

    /*!
     * @if jp
     * @brief �^�X�N�֐����s���Ԍv����L���ɂ��邩
     * @else
     * @brief Validate a Task execute time measurement
     * @endif
     */
    virtual void executionMeasure(bool value);
    
    /*!
     * @if jp
     * @brief �^�X�N�֐����s���Ԍv������
     * @else
     * @brief Task execute time measurement period
     * @endif
     */
    virtual void executionMeasureCount(int n);
    
    /*!
     * @if jp
     * @brief �^�X�N�������Ԍv����L���ɂ��邩
     * @else
     * @brief Validate a Task period time measurement
     * @endif
     */
    virtual void periodicMeasure(bool value);
    
    /*!
     * @if jp
     * @brief �^�X�N�������Ԍv������
     * @else
     * @brief Task period time measurement count
     * @endif
     */
    virtual void periodicMeasureCount(int n);
    
    /*!
     * @if jp
     * @brief �^�X�N�֐����s���Ԍv�����ʂ��擾
     * @else
     * @brief Get a result in task execute time measurement
     * @endif
     */
    virtual TimeMeasure::Statistics getExecStat();
    
    /*!
     * @if jp
     * @brief �^�X�N�������Ԍv�����ʂ��擾
     * @else
     * @brief Get a result in task period time measurement
     * @endif
     */
    virtual TimeMeasure::Statistics getPeriodStat();
    
  protected:
    /*!
     * @if jp
     * @brief PeriodicTask �p�̃X���b�h���s
     * @else
     * @brief Thread execution for PeriodicTask
     * @endif
     */
    virtual int svc();

    /*!
     * @if jp
     * @brief �X���b�h�x�~
     * @else
     * @brief Thread sleep
     * @endif
     */
    virtual void sleep();

    /*!
     * @if jp
     * @brief ���s��ԍX�V
     * @else
     * @brief Update for execute state
     * @endif
     */
    virtual void updateExecStat();

    /*!
     * @if jp
     * @brief ������ԍX�V
     * @else
     * @brief Update for period state
     * @endif
     */
    virtual void updatePeriodStat();

  protected:
    /*!
     * @if jp
     * @brief �^�X�N���s����
     * @else
     * @brief Task execution period
     * @endif
     */
    coil::TimeValue m_period;

    /*!
     * @if jp
     * @brief �X���b�h�x�~�t���O
     * @else
     * @brief Thread sleep flag
     * @endif
     */
    bool m_nowait;

    /*!
     * @if jp
     * @brief �^�X�N���s�֐�
     * @else
     * @brief Task execution function
     * @endif
     */
    TaskFuncBase* m_func;

    /*!
     * @if jp
     * @brief �^�X�N���s�֐��폜�t���O
     * @else
     * @brief Task execution function delete flag
     * @endif
     */
    bool m_deleteInDtor;

    /*!
     * @if jp
     * @class alive_t
     * @brief alive_t �N���X
     * @else
     * @class alive_t
     * @brief alive_t class
     * @endif
     */
    class alive_t
    {
    public:
      alive_t(bool val) : value(val) {}
      bool value;
      coil::Mutex mutex;
    };

    /*!
     * @if jp
     * @brief �^�X�N�����t���O
     * @else
     * @brief Task alive flag
     * @endif
     */
    alive_t m_alive;

    /*!
     * @if jp
     * @brief �^�X�N���f�Ǘ��p�\����
     * @else
     * @brief Structure for task suspend management
     * @endif
     */
    struct suspend_t
    {
      suspend_t(bool sus) : suspend(sus), mutex(), cond(mutex) {}
      bool suspend;
      coil::Mutex mutex;
      coil::Condition<coil::Mutex> cond;
    };

    /*!
     * @if jp
     * @brief �^�X�N���f���
     * @else
     * @brief Task suspend infomation
     * @endif
     */
    suspend_t m_suspend;
      
    /*!
     * @if jp
     * @brief �^�X�N���s���Ԍv���Ǘ��p�\����
     * @else
     * @brief Structure for task execution time measurement management
     * @endif
     */
    struct statistics_t
    {
      coil::TimeMeasure::Statistics stat;
      coil::Mutex mutex;
    };

    /*!
     * @if jp
     * @brief �^�X�N���s���Ԍv���t���O
     * @else
     * @brief Task execution time measurement flag
     * @endif
     */
    bool              m_execMeasure;

    /*!
     * @if jp
     * @brief �^�X�N���s���Ԍv����
     * @else
     * @brief Task execution time measurement count
     * @endif
     */
    unsigned int      m_execCount;

    /*!
     * @if jp
     * @brief �^�X�N���s���Ԍv������
     * @else
     * @brief Task execution time measurement max count
     * @endif
     */
    unsigned int      m_execCountMax;

    /*!
     * @if jp
     * @brief �^�X�N���s���Ԍv�����v
     * @else
     * @brief Task execution time measurement statistics
     * @endif
     */
    statistics_t      m_execStat;

    /*!
     * @if jp
     * @brief �^�X�N���s���Ԍv�����
     * @else
     * @brief Task execution time  measurement infomation
     * @endif
     */
    coil::TimeMeasure m_execTime;

    /*!
     * @if jp
     * @brief �^�X�N�������Ԍv���t���O
     * @else
     * @brief Task periodic time measurement flag
     * @endif
     */
    bool              m_periodMeasure;

    /*!
     * @if jp
     * @brief �^�X�N�������Ԍv����
     * @else
     * @brief Task periodic time measurement count
     * @endif
     */
    unsigned int      m_periodCount;

    /*!
     * @if jp
     * @brief �^�X�N�������Ԍv���ő吔
     * @else
     * @brief Task periodic time measurement max count
     * @endif
     */
    unsigned int      m_periodCountMax;

    /*!
     * @if jp
     * @brief �^�X�N�������Ԍv�����v
     * @else
     * @brief Task periodic time measurement statistics
     * @endif
     */
    statistics_t      m_periodStat;

    /*!
     * @if jp
     * @brief �^�X�N�������Ԍv�����
     * @else
     * @brief Task periodic time  measurement infomation
     * @endif
     */
    coil::TimeMeasure m_periodTime;

  };

}; // namespace coil

#endif // COIL_PERIODICTASK_H
