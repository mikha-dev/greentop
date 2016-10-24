/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CURRENTORDERSUMMARY_H
#define CURRENTORDERSUMMARY_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/PriceSize.h"
#include "greentop/sport/enum/OrderType.h"
#include "greentop/sport/enum/PersistenceType.h"
#include "greentop/sport/enum/Side.h"

namespace greentop {

/**
 * Summary of a current order.
 */
class CurrentOrderSummary : public JsonMember {
    public:
        CurrentOrderSummary();

        CurrentOrderSummary(const std::string& betId,
            const std::string& marketId,
            const int64_t selectionId,
            const double handicap,
            const PriceSize& priceSize,
            const double bspLiability,
            const Side& side,
            const std::string& status,
            const PersistenceType& persistenceType,
            const OrderType& orderType,
            const std::tm& placedDate,
            const std::tm& matchedDate,
            const Optional<double>& averagePriceMatched = Optional<double>(),
            const Optional<double>& sizeMatched = Optional<double>(),
            const Optional<double>& sizeRemaining = Optional<double>(),
            const Optional<double>& sizeLapsed = Optional<double>(),
            const Optional<double>& sizeCancelled = Optional<double>(),
            const Optional<double>& sizeVoided = Optional<double>(),
            const std::string& regulatorAuthCode = std::string(),
            const std::string& regulatorCode = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const int64_t getSelectionId() const;
        void setSelectionId(const int64_t selectionId);

        const double getHandicap() const;
        void setHandicap(const double handicap);

        const PriceSize& getPriceSize() const;
        void setPriceSize(const PriceSize& priceSize);

        const double getBspLiability() const;
        void setBspLiability(const double bspLiability);

        const Side& getSide() const;
        void setSide(const Side& side);

        const std::string& getStatus() const;
        void setStatus(const std::string& status);

        const PersistenceType& getPersistenceType() const;
        void setPersistenceType(const PersistenceType& persistenceType);

        const OrderType& getOrderType() const;
        void setOrderType(const OrderType& orderType);

        const std::tm& getPlacedDate() const;
        void setPlacedDate(const std::tm& placedDate);

        const std::tm& getMatchedDate() const;
        void setMatchedDate(const std::tm& matchedDate);

        const Optional<double>& getAveragePriceMatched() const;
        void setAveragePriceMatched(const Optional<double>& averagePriceMatched);

        const Optional<double>& getSizeMatched() const;
        void setSizeMatched(const Optional<double>& sizeMatched);

        const Optional<double>& getSizeRemaining() const;
        void setSizeRemaining(const Optional<double>& sizeRemaining);

        const Optional<double>& getSizeLapsed() const;
        void setSizeLapsed(const Optional<double>& sizeLapsed);

        const Optional<double>& getSizeCancelled() const;
        void setSizeCancelled(const Optional<double>& sizeCancelled);

        const Optional<double>& getSizeVoided() const;
        void setSizeVoided(const Optional<double>& sizeVoided);

        const std::string& getRegulatorAuthCode() const;
        void setRegulatorAuthCode(const std::string& regulatorAuthCode);

        const std::string& getRegulatorCode() const;
        void setRegulatorCode(const std::string& regulatorCode);


    private:
        /**
         * The bet ID of the original place order.
         */
        std::string betId;
        /**
         * The market id the order is for.
         */
        std::string marketId;
        /**
         * The selection id the order is for.
         */
        int64_t selectionId;
        /**
         * The handicap of the bet.
         */
        double handicap;
        /**
         * The price and size of the bet.
         */
        PriceSize priceSize;
        /**
         * Not to be confused with size. This is the liability of a given BSP bet.
         */
        double bspLiability;
        /**
         * BACK/LAY
         */
        Side side;
        /**
         * Either EXECUTABLE (an unmatched amount remains) or EXECUTION_COMPLETE (no unmatched
         * amount remains).
         */
        std::string status;
        /**
         * What to do with the order at turn-in-play.
         */
        PersistenceType persistenceType;
        /**
         * BSP Order type.
         */
        OrderType orderType;
        /**
         * The date, to the second, the bet was placed.
         */
        std::tm placedDate;
        /**
         * The date, to the second, of the last matched bet fragment (where applicable).
         */
        std::tm matchedDate;
        /**
         * The average price matched at. Voided match fragments are removed from this average
         * calculation.
         */
        Optional<double> averagePriceMatched;
        /**
         * The current amount of this bet that was matched.
         */
        Optional<double> sizeMatched;
        /**
         * The current amount of this bet that is unmatched.
         */
        Optional<double> sizeRemaining;
        /**
         * The current amount of this bet that was lapsed.
         */
        Optional<double> sizeLapsed;
        /**
         * The current amount of this bet that was cancelled.
         */
        Optional<double> sizeCancelled;
        /**
         * The current amount of this bet that was voided.
         */
        Optional<double> sizeVoided;
        /**
         * The regulator authorisation code.
         */
        std::string regulatorAuthCode;
        /**
         * The regulator Code.
         */
        std::string regulatorCode;
};

}

#endif // CURRENTORDERSUMMARY_H


