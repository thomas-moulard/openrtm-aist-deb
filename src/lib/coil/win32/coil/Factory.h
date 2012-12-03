// -*- C++ -*-
/*!
 * @file Factory.h
 * @brief generic Factory template class
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

#ifndef COIL_FACTORY_H
#define COIL_FACTORY_H

#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <coil/Singleton.h>

// for Windows DLL export
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#   ifdef LIBRARY_EXPORTS
#      define EXTERN
#      define DLL_PLUGIN __declspec(dllexport)
#   else
#      define EXTERN extern
#      define DLL_PLUGIN __declspec(dllimport)
#   endif
#else 
#   define DLL_PLUGIN
#   define EXTERN
#endif /* Windows */


namespace coil
{
  /*!
   * @if jp
   *
   * @brief Creator �e���v���[�g
   *
   * @else
   *
   * @brief Creator template
   *
   * @endif
   */
  template <class AbstractClass, class ConcreteClass>
  AbstractClass* Creator()
  {
    return new ConcreteClass();
  }

  /*!
   * @if jp
   *
   * @brief Destructor �e���v���[�g
   *
   * @else
   *
   * @brief Destructor template
   *
   * @endif
   */
  template <class AbstractClass, class ConcreteClass>
  void Destructor(AbstractClass*& obj)
  {
    if (obj == 0) { return; }
    ConcreteClass* tmp = dynamic_cast<ConcreteClass*>(obj);
    if (tmp == 0) { return; }
    delete obj;
    obj = 0;
  }

  /*!
   * @if jp
   *
   * @class Factory
   * @brief Factory �e���v���[�g�N���X
   *
   * @else
   *
   * @class Factory
   * @brief Factory template class
   *
   * @endif
   */
  template <
    class AbstractClass,
    typename Identifier = std::string,
    typename Compare = std::less<Identifier>,
    typename Creator = AbstractClass* (*)(),
    typename Destructor = void (*)(AbstractClass*&)
    >
  class Factory
  {
    class FactoryEntry;
  public:

    typedef std::map<Identifier, FactoryEntry> FactoryMap;
    typedef typename FactoryMap::iterator     FactoryMapIt;
    
    enum ReturnCode
      {
        FACTORY_OK,
        FACTORY_ERROR,
        ALREADY_EXISTS,
        NOT_FOUND,
        INVALID_ARG,
        UNKNOWN_ERROR
      };

    /*!
     * @if jp
     *
     * @brief �t�@�N�g���[�L���`�F�b�N
     *
     * �w��ID�̃t�@�N�g���[�L����Ԃ��B
     *
     * @param id �t�@�N�g���[ID
     *
     * @return true: �L��, false: ����
     *
     * @else
     *
     * @brief Factory presence check
     *
     * Return a factory having ID or not.
     *
     * @param id Factory ID.
     *
     * @return true: found, false: not found
     *
     * @endif
     */
    bool hasFactory(const Identifier& id)
    {
      if (m_creators.count(id) == 0) { return false; }
      return true;
    }

    /*!
     * @if jp
     *
     * @brief �t�@�N�g���[ID���X�g�擾
     *
     * �t�@�N�g���[ID���X�g��Ԃ��B
     *
     * @return ID ���X�g
     *
     * @else
     *
     * @brief Get factory ID list
     *
     * Return a list of factory ID.
     *
     * @return ID list
     *
     * @endif
     */
    std::vector<Identifier> getIdentifiers()
    {
      std::vector<Identifier> idlist;
      idlist.reserve(m_creators.size());

      FactoryMapIt it(m_creators.begin());
      FactoryMapIt it_end(m_creators.end());

      while (it != it_end)
        {
          idlist.push_back(it->first);
          ++it;
        }
      return idlist;
    }

    /*!
     * @if jp
     *
     * @brief �t�@�N�g���[�o�^
     *
     * �t�@�N�g���[��o�^����B
     *
     * @param id �t�@�N�g���[ID
     * @param creator �N���G�[�^�p�t�@���N�^
     * @param destructor �f�X�g���N�^�p�t�@���N�^
     *
     * @return FACTORY_OK: ����I��
     *         ALREADY_EXISTS: �o�^�ς�
     *         INVALID_ARG: creator �� destructor ���s���Ȓl���܂�
     *
     * @else
     *
     * @brief Add factory
     *
     * Add a factory.
     *
     * @param id Factory ID.
     * @param creator Functor for creator.
     * @param destructor Functor for destructor.
     *
     * @return FACTORY_OK: Successful
     *         ALREADY_EXISTS: already exists.
     *         INVALID_ARG: creator or destructor with invalid values.
     *
     * @endif
     */
    ReturnCode addFactory(const Identifier& id,
                          Creator creator,
                          Destructor destructor)
    {
      if (creator == 0 || destructor == 0) { return INVALID_ARG; }
      if (m_creators.count(id) != 0) { return ALREADY_EXISTS; }
      FactoryEntry f(creator, destructor);
      m_creators[id] = f;
      return FACTORY_OK;
    }

    /*!
     * @if jp
     *
     * @brief �t�@�N�g���[�폜
     *
     * �t�@�N�g���[���폜����B
     *
     * @param id �t�@�N�g���[ID
     *
     * @return FACTORY_OK: ����I��
     *         NOT_FOUND: ID���o�^
     *
     * @else
     *
     * @brief Remove factory
     *
     * Remove a factory.
     *
     * @param id Factory ID.
     *
     * @return FACTORY_OK: Successful
     *         NOT_FOUND: ID not found
     *
     * @endif
     */
    ReturnCode removeFactory(const Identifier& id)
    {
      if (m_creators.count(id) == 0) { return NOT_FOUND; }

      m_creators.erase(id);
      return FACTORY_OK;
    }

    /*!
     * @if jp
     *
     * @brief �t�@�N�g���[�I�u�W�F�N�g����
     *
     * �t�@�N�g���[�I�u�W�F�N�g�𐶐�����B
     *
     * @param id �t�@�N�g���[ID
     *
     * @return AbstractClass �̃|�C���^
     *
     * @else
     *
     * @brief Create factory object
     *
     * Create a factory object.
     *
     * @param id Factory ID.
     *
     * @return Pointer of AbstractClass
     *
     * @endif
     */
    AbstractClass* createObject(const Identifier& id)
    {
      if (m_creators.count(id) == 0) { return 0; }
      return m_creators[id].creator_();
    }

    /*!
     * @if jp
     *
     * @brief �t�@�N�g���[�I�u�W�F�N�g�폜
     *
     * �t�@�N�g���[�I�u�W�F�N�g���폜����B
     *
     * @param id �t�@�N�g���[ID
     * @param obj �t�@�N�g���[�I�u�W�F�N�g
     *
     * @else
     *
     * @brief Delete factory object
     *
     * Delete a factory object.
     *
     * @param id Factory ID.
     * @param obj Factory object.
     *
     * @endif
     */
    void deleteObject(const Identifier& id, AbstractClass*& obj)
    {
      if (m_creators.count(id) == 0) { return; }
      m_creators[id].destructor_(obj);
    }

    /*!
     * @if jp
     *
     * @brief �t�@�N�g���[�I�u�W�F�N�g�폜
     *
     * �t�@�N�g���[�I�u�W�F�N�g���폜����B
     *
     * @param obj �t�@�N�g���[�I�u�W�F�N�g
     *
     * @else
     *
     * @brief Delete factory object
     *
     * Delete a factory object.
     *
     * @param obj Factory object.
     *
     * @endif
     */
    void deleteObject(AbstractClass*& obj)
    {
      FactoryMapIt it(m_creators.begin());
      FactoryMapIt it_end(m_creators.end());

      while (it != it_end)
        {
          it->second.destructor_(obj);
          ++it;
        }
    }

  private:

    /*!
     * @if jp
     *
     * @class FactoryEntry
     * @brief FactoryEntry �N���X
     *
     * @else
     *
     * @class FactoryEntry
     * @brief FactoryEntry class
     *
     * @endif
     */
    class FactoryEntry
    {
    public:
      explicit FactoryEntry()
      {
      }

      /*!
       * @if jp
       *
       * @brief �R���X�g���N�^
       *
       * �R���X�g���N�^�B
       *
       * @param creator �N���G�[�^�p�t�@���N�^
       * @param destructor �f�X�g���N�^�p�t�@���N�^
       *
       * @else
       *
       * @brief Constructor
       *
       * Constructor
       *
       * @param creator Functor for creator.
       * @param destructor Functor for destructor.
       *
       * @endif
       */
      FactoryEntry(Creator creator, Destructor destructor)
        : creator_(creator), destructor_(destructor)
      {
      }
      Creator creator_;
      Destructor destructor_;
    };
    FactoryMap m_creators;
  };



  /*!
   * @if jp
   *
   * @class GlobalFactory
   * @brief GlobalFactory �e���v���[�g�N���X
   *
   * @else
   *
   * @class GlobalFactory
   * @brief GlobalFactory template class
   *
   * @endif
   */
  template <
    class AbstractClass,
    typename Identifier = std::string,
    typename Compare = std::less<Identifier>,
    typename Creator = AbstractClass* (*)(),
    typename Destructor = void (*)(AbstractClass*&)
    >
  class GlobalFactory
    : public Factory<AbstractClass, Identifier, Compare, Creator, Destructor>,
      public coil::Singleton<GlobalFactory<AbstractClass,
                                           Identifier,
                                           Compare,
                                           Creator,
                                           Destructor> >
  {
  public:

  private:
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
    GlobalFactory(){}

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
    ~GlobalFactory(){}

    friend class Singleton<GlobalFactory>;
  };

}; // namespace coil
#endif // COIL_FACTORY_H
