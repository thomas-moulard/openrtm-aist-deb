// -*- C++ -*-
/*!
 * @file Async.h
 * @brief Asynchronous function invocation helper class
 * @date $Date$
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2009
 *     Task-intelligence Research Group,
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id$
 *
 */

#ifndef COIL_ASYNC_H
#define COIL_ASYNC_H

#include <coil/Task.h>
#include <coil/Guard.h>
#include <iostream>

namespace coil
{
  /*!
   * @if jp
   *
   * @class Async
   * @brief Async �N���X
   *
   * @else
   *
   * @class Async
   * @brief Async class
   *
   * @endif
   */
  class Async
    : public coil::Task
  {
  public:
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
    Async() {}

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
    virtual ~Async(){}

    /*!
     * @if jp
     *
     * @brief �񓯊����s�p�������z�֐�
     *
     * �񓯊����s�p�������z�֐��B
     *
     * @else
     *
     * @brief Asynchronous invocation
     *
     * Pure virtual function for Asynchronous invocation.
     *
     * @endif
     */
    virtual void invoke() = 0;

    /*!
     * @if jp
     *
     * @brief ������ԃ`�F�b�N�p�������z�֐�
     *
     * ������ԃ`�F�b�N�p�������z�֐��B
     *
     * @return true: ����, false: ������
     *
     * @else
     *
     * @brief Check on completion state
     *
     * Pure virtual function for check on completion state.
     *
     * @return true: finished, false: unfinished
     *
     * @endif
     */
    virtual bool finished() = 0;
  };
  
  /*!
   * @if jp
   *
   * @class Async_t
   * @brief Async_t �e���v���[�g�N���X
   *
   * @else
   *
   * @class Async_t
   * @brief Async_t template class
   *
   * @endif
   */
  template <typename Object, typename Func>
  class Async_t
    : public Async
  {
  public:

    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^
     *
     * �R���X�g���N�^�B
     *
     * @param obj �o�^�ΏۃI�u�W�F�N�g
     * @param func �񓯊����s�p�֐�
     * @param auto_delete �񓯊����s�I�����Ɏ����I�ɃC���X�^���X�폜���s�����ǂ����̃t���O
     *
     * @else
     *
     * @brief Constructor
     *
     * Constructor
     *
     * @param obj The target object for the asynchronous function.
     * @param func Asynchronous function.
     * @param auto_delete flag for automatic instance destruction.
     *
     * @endif
     */
    Async_t(Object* obj, Func func, bool auto_delete = false)
      : m_obj(obj), m_func(func), m_finished(false), m_autodelete(auto_delete)
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
    virtual ~Async_t()
    {
    }
    
    /*!
     * @if jp
     *
     * @brief �񓯊������p�̃X���b�h���s�֐�
     *
     * �o�^���ꂽ�I�u�W�F�N�g�̔񓯊��������Ăяo���B
     *
     * @return ���s����
     *
     * @else
     *
     * @brief Thread execution function for asynchronous invoke.
     *
     * Invoke the registered objects operation.
     *
     * @return The execution result.
     *
     * @endif
     */
    virtual int svc()
    {
      m_func(m_obj);
      {
        Guard<Mutex> guard(m_mutex);
        m_finished = true;
      }
      
      return 0;
    }

    /*!
     * @if jp
     *
     * @brief �񓯊������I��
     *
     * �񓯊��������I�����A�C���X�^���X���폜����B
     *
     * @else
     *
     * @brief Finalize the asynchronous function
     *
     * Finalize the asynchronous function for preparing it for destruction.
     *
     * @endif
     */
    virtual void finalize()
    {
      Task::finalize();
      if (m_autodelete) delete this;
    }

    /*!
     * @if jp
     *
     * @brief �񓯊�����������
     *
     * �񓯊�����������������B
     *
     * @else
     *
     * @brief Asynchronous function Activation
     *
     * Activate of Asynchronous function.
     *
     * @endif
     */
    virtual void invoke()
    {
      activate();
    }

    /*!
     * @if jp
     *
     * @brief ������ԃ`�F�b�N
     *
     * ������Ԃ�Ԃ��B
     *
     * @return true: ����, false: ������
     *
     * @else
     *
     * @brief Check on completion state
     *
     * Return a completion state.
     *
     * @return true: finished, false: unfinished
     *
     * @endif
     */
    virtual bool finished()
    {
      Guard<Mutex> guard(m_mutex);
      return m_finished;
    }
  private:
    Object* m_obj;
    Func m_func;
    bool m_finished;
    const bool m_autodelete;
    Mutex m_mutex;
  };
  
  /*!
   * @if jp
   *
   * @class Async_ref_t
   * @brief Async_ref_t �e���v���[�g�N���X
   *
   * @else
   *
   * @class Async_ref_t
   * @brief Async_ref_t template class
   *
   * @endif
   */
  template <typename Object, typename Func>
  class Async_ref_t
    : public Async
  {
  public:

    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^
     *
     * �R���X�g���N�^�B
     *
     * @param obj �o�^�ΏۃI�u�W�F�N�g
     * @param func �񓯊����s�p�֐�
     * @param auto_delete �񓯊����s�I�����Ɏ����I�ɃC���X�^���X�폜���s�����ǂ����̃t���O
     *
     * @else
     *
     * @brief Constructor
     *
     * Constructor
     *
     * @param obj The target object for the asynchronous function.
     * @param func Asynchronous function.
     * @param auto_delete flag for automatic instance destruction.
     *
     * @endif
     */
    Async_ref_t(Object* obj, Func& func, bool auto_delete = false)
      : m_obj(obj), m_func(func), m_finished(false), m_autodelete(auto_delete)
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
    virtual ~Async_ref_t()
    {
    }
    
    /*!
     * @if jp
     *
     * @brief �񓯊������p�̃X���b�h���s�֐�
     *
     * �o�^���ꂽ�I�u�W�F�N�g�̔񓯊��������Ăяo���B
     *
     * @return ���s����
     *
     * @else
     *
     * @brief Thread execution function for asynchronous invoke.
     *
     * Invoke the registered objects operation.
     *
     * @return The execution result.
     *
     * @endif
     */
    virtual int svc()
    {
      m_func(m_obj);
      m_finished = true;
      return 0;
    }

    /*!
     * @if jp
     *
     * @brief �񓯊�����������
     *
     * �񓯊�����������������B
     *
     * @else
     *
     * @brief Asynchronous function Activation
     *
     * Activate of Asynchronous function.
     *
     * @endif
     */
    virtual void invoke()
    {
      activate();
    }

    /*!
     * @if jp
     *
     * @brief ������ԃ`�F�b�N
     *
     * ������Ԃ�Ԃ��B
     *
     * @return true: ����, false: ������
     *
     * @else
     *
     * @brief Check on completion state
     *
     * Return a completion state.
     *
     * @return true: finished, false: unfinished
     *
     * @endif
     */
    virtual bool finished()
    {
      return m_finished;
    }

    /*!
     * @if jp
     *
     * @brief �񓯊������I��
     *
     * �񓯊��������I�����A�C���X�^���X���폜����B
     *
     * @else
     *
     * @brief Finalize the asynchronous function
     *
     * Finalize the asynchronous function for preparing it for destruction.
     *
     * @endif
     */
    virtual void finalize()
    {
      Task::finalize();
      if (m_autodelete) delete this;
    }
  private:
    Object* m_obj;
    Func& m_func;
    bool m_finished;
    bool m_autodelete;
    
  };
  
  /*!
   * @if jp
   * @brief �񓯊������o�[�֐��Ăяo���w���p�[�֐�
   *
   * �����o�[�֐���񓯊��ɌĂԂ��߂̃w���p�[�֐�
   * ��
   *
   *  class A
   *  {
   *  public:
   *    // ���Ԃ̂�����֐�
   *    void hoge() {
   *      for (int i(0); i < 5; ++i) {
   *        std::cout << "hoge" << std::endl;
   *        sleep(1);
   *      }
   *    }
   *    // ���Ԃ̂�����֐�
   *    void munya(const char* msg) {
   *      for (int i(0); i < 10; ++i) {
   *        std::cout << "message is: " << msg << std::endl;
   *        sleep(1);
   *      }
   *    }
   *    int add_one(int val) {
   *      return val + 1;
   *    }
   *  };
   * ���̗l�ȃN���X�̃I�u�W�F�N�g�ɑ΂��āA
   *
   *  A a;
   *  Async* invoker0(AsyncInvoker(&a,
   *                               std::mem_fun(&A::hoge)));
   *  Async* invoker1(AsyncInvoker(&a,
   *                               std::bind2nd(std::mem_fun(&A::munya),
   *                                            "�ق�")));
   *  invoker0->invoke(); // �����ɖ߂�
   *  invoker1->invoke(); // �����ɖ߂�
   *
   *  delete invoker0; // �K���폜���邱��
   *  delete invoker1; // �K���폜���邱��
   *
   * �̂悤�ɔ񓯊��̌Ăяo�����ł���B
   * �Ăяo���̖߂�l���擾�������ꍇ�́A���O�̊֐��I�u�W�F�N�g��p�ӂ���B
   *
   *  class add_one_functor
   *  {
   *    int m_val, m_ret;
   *  public:
   *    add_one_functor(int val) : m_val(val), m_ret(0) {}
   *    void operaotr(A* obj) {
   *      m_ret = obj->add_one(m_val);
   *    }
   *    int get_ret() {
   *      return m_ret;
   *    }
   *  };
   *
   * ��L�̊֐��I�u�W�F�N�g�̃C���X�^���X���쐬���A���̃|�C���^��n���B
   *
   *  add_one_functor aof(100);
   *  Async* invoker2(AsyncInvoker(&a, &aof));
   *  invoker2->invoke();
   *  invoker2->wait();
   *  std::cout << "result: " << aof.get_ret() << std::endl;
   *  delete invoker2;
   *
   * �ʏ�AAsyncInvoker ���Ԃ��I�u�W�F�N�g�͖����I�ɍ폜���Ȃ����
   * �Ȃ�Ȃ����A��O������ true ��n�����ƂŁA�񓯊����s���I������Ɠ�����
   * �����I�ɃC���X�^���X���폜�����B
   *
   * // invoker3 �͍폜 (delete invoker3) ���Ă͂����Ȃ�
   * Async* invoker3(AsyncInvoker(&a, std::mem_fun(&A::hoge), true));
   *
   * // �C���X�^���X�����Ɠ����Ɏ��s���邱�Ƃ��ł���B
   * AsyncInvoker(&a, std::mem_fun(&A::hoge))->invoke();
   *
   * @param obj �o�^�ΏۃI�u�W�F�N�g
   * @param func �񓯊����s�p�֐�
   * @param auto_delete �񓯊����s�I�����Ɏ����I�ɃC���X�^���X�폜���s�����ǂ����̃t���O
   *
   * @return Async_t �C���X�^���X
   *
   * @else
   *
   * @brief Helper function for async member function summons
   *
   * Helper function for async member function summons.
   *
   * @param obj The target object for the asynchronous function.
   * @param func Asynchronous function.
   * @param auto_delete flag for automatic instance destruction.
   *
   * @return Async_t Instance
   *
   * @endif
   */
  template <typename Object, typename Func>
  inline Async_t<Object, Func>*
  AsyncInvoker(Object* obj, Func func, bool auto_delete = false)
  {
    return new Async_t<Object, Func>(obj, func, auto_delete);
  }

  /*!
   * @if jp
   *
   * @brief �񓯊������o�[�֐��Ăяo���w���p�[�֐�
   *
   * �����o�[�֐���񓯊��ɌĂԂ��߂̃w���p�[�֐�
   *
   * @param obj �o�^�ΏۃI�u�W�F�N�g
   * @param func �񓯊����s�p�֐�
   * @param auto_delete �񓯊����s�I�����Ɏ����I�ɃC���X�^���X�폜���s�����ǂ����̃t���O
   *
   * @return Async_ref_t �C���X�^���X
   *
   * @else
   *
   * @brief Helper function for async member function summons
   *
   * Helper function for async member function summons.
   *
   * @param obj The target object for the asynchronous function.
   * @param func Asynchronous function.
   * @param auto_delete flag for automatic instance destruction.
   *
   * @return Async_ref_t Instance
   *
   * @endif
   */
  template <typename Object, typename Func>
  inline Async_ref_t<Object, Func>*
  AsyncInvoker(Object* obj, Func* func, bool auto_delete = false)
  {
    return new Async_ref_t<Object, Func>(obj, *func, auto_delete);
  }


};

#endif // COIL_ASYNC_H
