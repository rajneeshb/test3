<?php
  setlocale(LC_MONETARY, 'en_US.UTF-8');
  drupal_add_css( path_to_theme() . '/css/project-view.css' );
  drupal_add_css( 'sites/all/libraries/jquery.alerts-1.1/jquery.alerts.css', 'theme' );
  drupal_add_js( 'sites/all/libraries/jquery.alerts-1.1/jquery.alerts.js', 'theme' );
  drupal_add_js( path_to_theme() . '/js/order.view.js', 'theme' );

  $court_type = t('Not specified');
  if ( !empty($node->field_locationref[0]['nid']) ) {
    $court_type = node_load($node->field_locationref[0]['nid']);
    $court_type = check_plain( $court_type->field_providertype[0]['value'] );
  }

  unset($terms);  // We don't want the taxonomy to show on this page
  ob_start();
?>
<div class="order-view">
  <fieldset id="case_information">
    <legend>Case Information</legend>

    <div>
      <label class="field-label">Case number:</label>
      <span class="field-value"><?php echo $node->field_case_number[0]['view']; ?></span>
    </div>

    <div>
      <label class="field-label">Court type:</label>
      <span class="field-value"><?php echo $court_type; ?></span>
    </div>

    <div>
      <label class="field-label">Hearing location:</label>
      <span class="field-value"><?php echo $node->field_locationref[0]['view']; ?></span>
    </div>

    <div>
      <label class="field-label">Appeal number:</label>
      <span class="field-value"><?php echo 'yes' === $node->field_appealtranscript[0]['value'] ?
                                            $node->field_appeal_number[0]['view'] :
                                            t('Not for appeal');
                              ?></span>
    </div>

    <div>
      <label class="field-label">Hearing date(s):</label>
      <?php foreach ($node->field_hearingdate as $hearing_date) : ?>
        <span class="field-value"><?php echo $hearing_date['view']; ?></span>
      <?php endforeach; ?>
    </div>

    <div>
      <label class="field-label">Length of hearing:</label>
      <?php foreach ($node->field_hearingdate as $idx => $hearing_date) : ?>
        <span class="field-value"><?php
          $time_parts = array();
          if ( !empty($node->field_estimatedhours[$idx]['value']) ) {
            $time_parts[] = format_plural($node->field_estimatedhours[$idx]['value'] , '1 hour', '@count hours');
          }

          if ( !empty($node->field_estimatedminutes[$idx]['value']) ) {
            $time_parts[] = format_plural($node->field_estimatedminutes[$idx]['value'] , '1 minute', '@count minutes');
          }

          echo implode(', ', $time_parts);
        ?></span>
      <?php endforeach; ?>
    </div>
    <?php module_load_include('class', 'avtstore_orders', 'AVTCostCalculator'); ?>
    <?php if ( class_exists('AVTCostCalculator') ) : ?>
      <div>
        <label class="field-label">Estimated pages:</label>
        <?php $estimates = AVTCostCalculator::calculateFromNode($node); ?>
        <?php foreach ($estimates['info']['hearings'] as $hearing ) : ?>
          <span class="field-value"><?php echo format_plural($hearing['pages'], '1 page', '@count pages'); ?></span>
        <?php endforeach; ?>
      </div>
    <?php endif; ?>
  </fieldset>

  <fieldset>
    <legend>Order information</legend>

    <div>
      <div class="left-column">
        <label class="field-label">Confirmation number:</label>
        <span class="field-value"><?php echo $node->nid; ?></span>
      </div>
      <div class="right-column">
        <label class="field-label">Order created:</label>
        <span class="field-value"><?php echo format_date( $node->created, 'small'); ?></span>
      </div>
    </div>

    <div>
      <div class="left-column">
        <label class="field-label">Transcribe selections:</label>
        <?php foreach ($node->field_transcribeextra as $extra ) : ?>
          <span class="field-value"><?php echo $extra['view']; ?></span>
        <?php endforeach; ?>
      </div>

      <div class="right-column">
        <label class="field-label">Turnaround time:</label>
        <span class="field-value"><?php echo $node->field_turnaroundtime[0]['view']; ?></span>
      </div>
    </div>

    <div>
      <div class="left-column">
        <label class="field-label">Witnesses:</label>
        <span class="field-value"><?php echo empty($node->field_witnesses[0]['value']) ? t('None') : $node->field_witnesses[0]['safe']; ?></span>
      </div>

      <div class="right-column">
        <label class="field-label">Additional formats:</label>
        <?php foreach ($node->field_otherformats as $format ) : ?>
          <span class="field-value"><?php echo $format['view']; ?></span>
        <?php endforeach; ?>
      </div>
    </div>

    <div>
      <div class="left-column">
        <label class="field-label">Completion date:</label>
        <span class="field-value"><?php echo empty($node->field_completiondate[0]['value']) ? t('In progress') : $node->field_completiondate[0]['view']; ?></span>
      </div>

      <div class="right-column">
        <div class="right-column">
          <label class="field-label">Estimated pages:</label>
          <span class="field-value"><?php echo $node->field_estimated_pages[0]['view']; ?></span>
        </div>
        <div class="left-column">
          <label class="field-label">Actual pages:</label>
          <span class="field-value"><?php echo $node->field_actual_pages[0]['view']; ?></span>
        </div>
      </div>
    </div>


    <div>
      <div class="left-column">
        <label class="field-label">Are copy pages included?</label>
        <span class="field-value"><?php echo empty($node->field_copy_order[0]['view']) ?
                                                t('No') :
                                                $node->field_copy_order[0]['view'];
                                  ?></span>
      </div>

      <div class="right-column">
        <div class="left-column">
          <label class="field-label">Estimated cost:</label>
          <span class="field-value"><?php echo money_format( '%n', $node->field_estimated_cost[0]['value'] ); ?></span>
        </div>

        <div class="right-column">
          <label class="field-label">Actual cost:</label>
          <span class="field-value">
            <?php
              if ($node->field_actual_cost[0]['value'] && $node->field_actual_cost[0]['value'] != '0.00') {
                echo money_format( '%n', $node->field_actual_cost[0]['value'] );
              }
              else {
                echo '';
              }
            ?>
          </span>
        </div>
      </div>
    </div>

    <?php if ( user_access('view field_associated_parties') ) : ?>
      <div>
        <label class="field-label">Associated parties:</label>
        <span class="field-value"><?php echo empty($node->field_associated_parties[0]['view']) ?
                                              t('None') :
                                              $node->field_associated_parties[0]['view'];
                                  ?></span>
      </div>
    <?php endif; ?>
  </fieldset>

  <fieldset>
    <legend>Payment information</legend>

    <div>
        <div class="left-column">
          <label class="field-label">Deposit required:</label>
          <span class="field-value"><?php echo empty($node->field_deposit_required[0]['view']) ?
                                                t('No') :
                                                $node->field_deposit_required[0]['view'];
                                    ?></span>
        </div>
        <div class="left-column">
          <label class="field-label">Payment method:</label>
          <span class="field-value"><?php echo $node->field_how_to_pay[0]['view']; ?></span>
        </div>
    </div>

    <div>
      <div class="left-column">
        <label class="field-label">Amount due/Refund owed:</label>
        <span class="field-value"><?php echo _avtstore_orders_calculate_balance_due($node, TRUE, TRUE); ?></span>
      </div>
    </div>

    <div>
      <div class="left-column">
        <label class="field-label">Deposit paid:</label>
        <span class="field-value"><?php echo money_format( '%n', $node->field_deposit_paid[0]['value']); ?></span>
      </div>
      <div class="right-column">
        <label class="field-label">Additional paid/Refund amount:</label>
        <span class="field-value"><?php echo money_format( '%n', $node->field_balance_paid[0]['value']); ?></span>
      </div>
    </div>

    <div>
      <div class="left-column">
        <label class="field-label">Deposit paid date:</label>
        <span class="field-value"><?php echo $node->field_deposit_paid_date[0]['view']; ?></span>
      </div>
      <div class="right-column">
        <label class="field-label">Additional paid/refund date:</label>
        <span class="field-value"><?php echo $node->field_balance_paid_date[0]['view']; ?></span>
      </div>
    </div>
  </fieldset>

  <fieldset>
    <legend>Additional information</legend>

    <div>
        <label class="field-label">Comments:</label>
        <span class="field-value"><?php echo empty($node->field_additional_comments[0]['view']) ?
                                              t('None') :
                                              nl2br( $node->field_additional_comments[0]['view'] );
                                  ?></span>
    </div>

  </fieldset>
</div>
<?php

  $stuff = ob_get_contents();
  ob_end_clean();
  $content = $stuff;
  include 'node.tpl.php';
