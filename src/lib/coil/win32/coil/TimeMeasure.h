// -*- C++ -*-
/*!
 * @file TimeMeasure.h
 * @brief Periodic time measurement class
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

#ifndef COIL_TIMEMEASURE_H
#define COIL_TIMEMEASURE_H

#include <vector>
#include <coil/TimeValue.h>

namespace coil
{
  
  /*!
   * @if jp
   *
   * @class TimeMeasure
   * @brief TimeMeasure �N���X
   *
   * ���̃N���X�́A�R�[�h���s���Ԃ̓��v�����ׂɎg�p���܂��B
   * get_stat ���g�p���ăR�[�h���s�̍ő�E�ŏ��E���ρE�W���΍����Ԃ��v���ł��܂��B
   *
   * @else
   *
   * @class TimeMeasure
   * @brief TimeMeasure class
   *
   * This class is used for getting statistics of code execution time. 
   * Using get_stat you can get maximum, minimum, mean and standard
   * deviation time for code execution.
   *
   * @endif
   */
  class TimeMeasure
  {
  public:
    /*!
     * @if jp
     *
     * @brief ���ԓ��v�p�\����
     *
     * @else
     *
     * @brief Structure for time statistics
     *
     * @endif
     */
    struct Statistics
    {
      double max_interval;
      double min_interval;
      double mean_interval;
      double std_deviation;
    };

    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^
     *
     * ���ԓ��v�̃v���t�@�C�����O
     *
     * @else
     *
     * @brief Constructor
     *
     * Time Statistics object for profiling.
     *
     * @endif
     */
    TimeMeasure(int buflen = 100);

    /*!
     * @if jp
     *
     * @brief ���ԓ��v�̌v�����J�n����
     *
     * ���ԓ��v�̌v�����J�n����
     *
     * @else
     *
     * @brief Begin time measurement for time statistics
     *
     * Begin time measurement for time statistics.
     *
     * @endif
     */
    void tick();

    /*!
     * @if jp
     *
     * @brief ���ԓ��v�̌v�����I������
     *
     * ���ԓ��v�̌v�����I������
     *
     * @else
     *
     * @brief Finish time measurement for time statistics
     *
     * End of time measurement for time statistics.
     *
     * @endif
     */
    void tack();

    /*!
     * @if jp
     *
     * @brief �o�ߎ��Ԃ��擾����
     *
     * �o�ߎ��Ԃ��擾����
     *
     * @return TimeValue �I�u�W�F�N�g
     *
     * @else
     *
     * @brief Get a interval time
     *
     * Get a interval time.
     *
     * @return TimeValue object
     *
     * @endif
     */
    coil::TimeValue& interval();

    /*!
     * @if jp
     *
     * @brief ���v�֘A�f�[�^�̏�����
     *
     * ���v�֘A�f�[�^�̏�����
     *
     * @else
     *
     * @brief Initialize for statistics related data
     *
     * Initialize for statistics related data.
     *
     * @endif
     */
    void reset();

    /*!
     * @if jp
     *
     * @brief ���ԓ��v�o�b�t�@�T�C�Y���擾����
     *
     * ���ԓ��v�o�b�t�@�T�C�Y���擾����
     *
     * @return �v������
     *
     * @else
     *
     * @brief Get number of time measurement buffer
     *
     * Get number of time measurement buffer.
     *
     * @return Measurement count
     *
     * @endif
     */
    unsigned long int count() const;

    /*!
     * @if jp
     *
     * @brief ���v�f�[�^�̑��v���擾����
     *
     * ���v�f�[�^�̑��v���擾����
     *
     * @param max_interval �ő�l [ns]
     * @param min_interval �ŏ��l [ns]
     * @param mean_interval ���ϒl [ns]
     * @param stddev �W���΍��l
     *
     * @return true: �f�[�^����, false: �f�[�^�Ȃ�
     *
     * @else
     *
     * @brief Get total statistics
     *
     * Get total statistics.
     *
     * @param max_interval Max value [ns]
     * @param min_interval Min value [ns]
     * @param mean_interval Mean value [ns]
     * @param stddev Standard deviation value
     *
     * @return true: Data found, false: Data not found
     *
     * @endif
     */
    bool getStatistics(double &max_interval,
                       double &min_interval,
                       double &mean_interval,
                       double &stddev);

    /*!
     * @if jp
     *
     * @brief ���v���ʂ��擾����
     *
     * ���v���ʂ��擾����
     *
     * @return ���v����
     *
     * @else
     *
     * @brief Get statistics result
     *
     * Get statistics result.
     *
     * @return Statistics result
     *
     * @endif
     */
    Statistics getStatistics();

  private:
    std::vector<coil::TimeValue> m_record;
    coil::TimeValue m_begin;
    coil::TimeValue m_interval;

    unsigned long int m_count;
    const unsigned long int m_countMax;
    unsigned long long int m_cpuClock;

    bool m_recurred;
  };
}; // namespace coil
#endif // COIL_TIMEMEASURE_H
