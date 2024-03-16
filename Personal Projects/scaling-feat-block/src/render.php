<?php
  $feat_Title = $attributes['featTitle'];
  $show_Flavor_Field = $attributes['showFlavorField'];
  $feat_Flavor = $attributes['featFlavor'];
  $feat_Prerequisites = $attributes['featPrerequisites'];
  $feat_Benefit = $attributes['featBenefit'];
  $feat_Threshold_Count = $attributes['featThresholdCount'];

  $feat_Scale_Threshold_1 = $attributes['featScaleThreshold1'];
  $feat_Scale_Benefit_1 = $attributes['featScaleBenefit1'];
  $feat_Scale_Threshold_2 = $attributes['featScaleThreshold2'];
  $feat_Scale_Benefit_2 = $attributes['featScaleBenefit2'];
  $feat_Scale_Threshold_3 = $attributes['featScaleThreshold3'];
  $feat_Scale_Benefit_3 = $attributes['featScaleBenefit3'];
  $feat_Scale_Threshold_4 = $attributes['featScaleThreshold4'];
  $feat_Scale_Benefit_4 = $attributes['featScaleBenefit4'];
  $feat_Scale_Threshold_5 = $attributes['featScaleThreshold5'];
  $feat_Scale_Benefit_5 = $attributes['featScaleBenefit5'];
  $feat_Scale_Threshold_6 = $attributes['featScaleThreshold6'];
  $feat_Scale_Benefit_6 = $attributes['featScaleBenefit6'];
  $feat_Scale_Threshold_7 = $attributes['featScaleThreshold7'];
  $feat_Scale_Benefit_7 = $attributes['featScaleBenefit7'];
  $feat_Scale_Threshold_8 = $attributes['featScaleThreshold8'];
  $feat_Scale_Benefit_8 = $attributes['featScaleBenefit8'];
  $feat_Scale_Threshold_9 = $attributes['featScaleThreshold9'];
  $feat_Scale_Benefit_9 = $attributes['featScaleBenefit9'];
  $feat_Scale_Threshold_10 = $attributes['featScaleThreshold10'];
  $feat_Scale_Benefit_10 = $attributes['featScaleBenefit10'];

  $show_Special_Field = $attributes['showSpecialField'];
  $feat_Specials = $attributes['featSpecials'];
?>

<div <?php echo get_block_wrapper_attributes(); ?>>
	<h4><?php echo esc_html($feat_Title); ?></h4>
  <?php if ($show_Flavor_Field): ?>
    <p><i><?php echo esc_html($feat_Flavor) ?></i></p>
  <?php endif; ?>
  <p><strong>Prerequisite(s): </strong><?php echo esc_html($feat_Prerequisites) ?></p>
  <p><strong>Benefit: </strong><?php echo esc_html($feat_Benefit) ?></p>
  <?php if ($feat_Threshold_Count >= 1): ?>
    <p>
      <strong><?php echo esc_html($feat_Scale_Threshold_1) ?>: </strong>
      <?php echo esc_html($feat_Scale_Benefit_1)?>
    </p>
  <?php endif; ?>
  <?php if ($feat_Threshold_Count >= 2): ?>
    <p>
      <strong><?php echo esc_html($feat_Scale_Threshold_2) ?>: </strong>
      <?php echo esc_html($feat_Scale_Benefit_2)?>
    </p>
  <?php endif; ?>
  <?php if ($feat_Threshold_Count >= 3): ?>
    <p>
      <strong><?php echo esc_html($feat_Scale_Threshold_3) ?>: </strong>
      <?php echo esc_html($feat_Scale_Benefit_3)?>
    </p>
  <?php endif; ?>
  <?php if ($feat_Threshold_Count >= 4): ?>
    <p>
      <strong><?php echo esc_html($feat_Scale_Threshold_4) ?>: </strong>
      <?php echo esc_html($feat_Scale_Benefit_4)?>
    </p>
  <?php endif; ?>
  <?php if ($feat_Threshold_Count >= 5): ?>
    <p>
      <strong><?php echo esc_html($feat_Scale_Threshold_5) ?>: </strong>
      <?php echo esc_html($feat_Scale_Benefit_5)?>
    </p>
  <?php endif; ?>
  <?php if ($feat_Threshold_Count >= 6): ?>
    <p>
      <strong><?php echo esc_html($feat_Scale_Threshold_6) ?>: </strong>
      <?php echo esc_html($feat_Scale_Benefit_6)?>
    </p>
  <?php endif; ?>
  <?php if ($feat_Threshold_Count >= 7): ?>
    <p>
      <strong><?php echo esc_html($feat_Scale_Threshold_7) ?>: </strong>
      <?php echo esc_html($feat_Scale_Benefit_7)?>
    </p>
  <?php endif; ?>
  <?php if ($feat_Threshold_Count >= 8): ?>
    <p>
      <strong><?php echo esc_html($feat_Scale_Threshold_8) ?>: </strong>
      <?php echo esc_html($feat_Scale_Benefit_8)?>
    </p>
  <?php endif; ?>
  <?php if ($feat_Threshold_Count >= 9): ?>
    <p>
      <strong><?php echo esc_html($feat_Scale_Threshold_9) ?>: </strong>
      <?php echo esc_html($feat_Scale_Benefit_9)?>
    </p>
  <?php endif; ?>
  <?php if ($feat_Threshold_Count >= 10): ?>
    <p>
      <strong><?php echo esc_html($feat_Scale_Threshold_10) ?>: </strong>
      <?php echo esc_html($feat_Scale_Benefit_10)?>
    </p>
  <?php endif; ?>
  <?php if ($show_Special_Field): ?>
    <p><strong>Special: </strong><?php echo esc_html($feat_Specials) ?></p>
  <?php endif; ?>
</div>
