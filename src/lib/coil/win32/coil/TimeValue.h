// -*- C++ -*-
/*!
 * @file Timevalue.h
 * @brief Timevalue class
 * @date $Date$
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2008
 *     Task-intelligence Research Group,
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id$
 *
 */

#ifndef COIL_TIMEVALUE_H
#define COIL_TIMEVALUE_H

namespace coil
{

#define TIMEVALUE_ONE_SECOND_IN_USECS 1000000 // 1 [sec] = 1000000 [usec]

  /*!
   * @if jp
   *
   * @class TimeValue
   * @brief TimeValue �N���X
   *
   * @else
   *
   * @class TimeValue
   * @brief TimeValue class
   *
   * @endif
   */
  class TimeValue
  {
  public:
    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^
     * 
     * �R���X�g���N�^
     * �w�肳�ꂽ�b�C�}�C�N���b�ŏ���������B
     *
     * @param sec �b(�f�t�H���g�l:�[��)
     * @param usec �}�C�N���b(�f�t�H���g�l:�[��)
     * 
     * @else
     *
     * @brief Constructor
     * 
     * Constructor
     * Initialize with the specified second and micro second.
     *
     * @param sec Second(The default value:0)
     * @param usec Micro second(The default value:0)
     * 
     * @endif
     */
    TimeValue(long sec=0, long usec=0);

    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^
     * 
     * �R���X�g���N�^
     * �w�肳�ꂽ�b�C�}�C�N���b�ŏ���������B
     *
     * @param timeval (�b * 1000000 + �}�C�N���b)
     * 
     * @else
     *
     * @brief Constructor
     * 
     * Constructor
     * Initialize with the specified second and micro second.
     *
     * @param timeval (Second * 1000000 + Micro second)
     * 
     * @endif
     */
    TimeValue(double timeval);

    /*!
     * @if jp
     *
     * @brief �b�P�ʂ̒l���擾����
     * 
     * �b�P�ʂ̒l���擾����
     *
     * @return �l
     *
     * @else
     *
     * @brief Get value of second time scale
     * 
     * Get value of second time scale.
     *
     * @return value
     *
     * @endif
     */
    inline long int sec() const {return m_sec;}

    /*!
     * @if jp
     *
     * @brief �}�C�N���b�P�ʂ̒l���擾����
     * 
     * �}�C�N���b�P�ʂ̒l���擾����
     *
     * @return �l
     *
     * @else
     *
     * @brief Get value of micro second time scale
     * 
     * Get value of micro second time scale.
     *
     * @return value
     *
     * @endif
     */
    inline long int usec() const {return m_usec;}
    
    /*!
     * @if jp
     *
     * @brief ���Ԍ��Z
     * 
     * �ݒ肳�ꂽ���Ԃ�������ŗ^����ꂽ���Ԃ����Z����B
     *
     * @param tm ���Z����
     * 
     * @return ���Z����
     * 
     * @else
     *
     * @brief Time subtraction
     * 
     * Subtract the time given by the argument from the set time.
     *
     * @param tm Subtracted time
     * 
     * @return Subtraction result
     * 
     
     * @endif
     */
    TimeValue operator-(TimeValue& tm);
    
    /*!
     * @if jp
     *
     * @brief ���ԉ��Z
     * 
     * �ݒ肳�ꂽ���ԂɈ����ŗ^����ꂽ���Ԃ����Z����B
     *
     * @param tm ���Z����
     * 
     * @return ���Z����
     * 
     * @else
     *
     * @brief Time addition
     * 
     * Add the time given by the argument to the set time.
     *
     * @param tm Added time
     * 
     * @return Addition result
     * 
     * @endif
     */
    TimeValue operator+(TimeValue& tm);
    
    /*!
     * @if jp
     *
     * @brief double�^�����Ԍ^�ϊ�
     * 
     * �����ŗ^����ꂽdouble�^�����Ԍ^�ɕϊ�����B
     *
     * @param time �ϊ����l
     * 
     * @return �ϊ�����
     * 
     * @else
     *
     * @brief Convert double type into time type
     * 
     * Convert double type given by the argument into time type.
     *
     * @param time the original value
     * 
     * @return Conversion result
     * 
     * @endif
     */
    TimeValue operator=(double time);
    
    /*!
     * @if jp
     *
     * @brief ���Ԍ^��double�^�ϊ�
     * 
     * �ێ����Ă�����e��double�^�ɕϊ�����B
     *
     * @return double�^�ϊ�����
     * 
     * @else
     *
     * @brief Convert time type into double type
     * 
     * Convert held information into double type.
     *
     * @return Result for conversion of double type
     * 
     * @endif
     */
    operator double() const;
    
    /*!
     * @if jp
     * 
     * @brief ��������
     * 
     * �ێ����Ă�����e�̕����𔻒肷��B
     * 
     * @return ���Ȃ��1���A���Ȃ��-1���A0�Ȃ��0
     * 
     * @else
     *  
     * @brief Sign judgment
     * 
     * Judge sign of the held contents
     * 
     * @return 1 if the return value is Plus sign, -1 if Minus, and 0 if 0.
     * 
     * @endif
     */
    int sign() const;
    
    //  private:
    
    /*!
     * @if jp
     * 
     * @brief ���K��
     * 
     * �l�̕\���𐳏��`���ɐ��K������B
     * 
     * @else
     * 
     * @brief Normalize
     * 
     * Normalize the value expression into a canonical form.
     * 
     * @endif
     */
    void normalize();

  private:
    long int m_sec;
    long int m_usec;
  };
};

#endif // COIL_TIMEVALUE_H
