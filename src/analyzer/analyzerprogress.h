#pragma once

#include "util/math.h"


typedef double AnalyzerProgress;

constexpr AnalyzerProgress kAnalyzerProgressUnknown    = -1.0;
constexpr AnalyzerProgress kAnalyzerProgressNone       =  0.0;  //   0.0 %
constexpr AnalyzerProgress kAnalyzerProgressHalf       =  0.5;  //  50.0 %
constexpr AnalyzerProgress kAnalyzerProgressFinalizing =  0.95; //  95.0 %
constexpr AnalyzerProgress kAnalyzerProgressDone       =  1.0;  // 100.0%

Q_DECLARE_METATYPE(AnalyzerProgress);

// Integer [0, 100]
inline
int analyzerProgressPercent(AnalyzerProgress analyzerProgress) {
    DEBUG_ASSERT(analyzerProgress >= kAnalyzerProgressNone);
    return int((100 * (math_min(analyzerProgress, kAnalyzerProgressDone) - kAnalyzerProgressNone)) /
            (kAnalyzerProgressDone - kAnalyzerProgressNone));
}
