/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETRATES_H
#define MARKETRATES_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

/**
 * Market Rates
 */
class MarketRates : public JsonMember {
    public:
        MarketRates();

        MarketRates(const double marketBaseRate,
            const bool discountAllowed);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const double getMarketBaseRate() const;
        void setMarketBaseRate(const double marketBaseRate);

        const bool getDiscountAllowed() const;
        void setDiscountAllowed(const bool discountAllowed);


    private:
        /**
         * marketBaseRate
         */
        Optional<double> marketBaseRate;
        /**
         * discountAllowed
         */
        Optional<bool> discountAllowed;
};

}

#endif // MARKETRATES_H


